
#include "Windows.h"
#include <gl/GL.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

double horizAngle = 0.0;	
double vertAngle = 0.0;	
double limbAngle = 0.0; //ângulo da passada do robo
bool walk = false;	

void drawRobot() {
	//cabeça
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.0, 1.0, 0.0);
	glutSolidSphere(.25, 20, 20);
	glPopMatrix();

	//corpo
	glColor3f(0.0, 0.60, 1.0);
	glPushMatrix();
	glTranslated(0.0, 0.40, 0.0);
	glScaled(1.0, 1.5, 0.30);
	glutSolidCube(.50);
	glPopMatrix();


}
//Braço esquerdo
void leftArm() {
	glColor3f(1.0, 0.0, 1.0);
	glPushMatrix();
	glTranslated(-0.30, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glColor3f(0.0, 0.60, 1.0);
	glPushMatrix();
	glTranslated(-0.270, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.33, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	
	//mãos
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(-0.30, 0.17, 0.0);
	glScaled(0.80, 1.0, 1.0);
	glutSolidSphere(.08, 20, 20);
	glPopMatrix();

}
//braço direito
void rightArm() {
	glColor3f(1.0, 0.0, 1.0);
	glPushMatrix();
	glTranslated(0.30, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glColor3f(0.0, 0.60, 1.0);
	glPushMatrix();
	glTranslated(0.270, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.33, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	
	//mão
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.30, 0.17, 0.0);
	glScaled(0.80, 1.0, 1.0);
	glutSolidSphere(.08, 20, 20);
	glPopMatrix();
}
//perna esquerda
void leftLeg() {
	glColor3f(0.0, 0.60, 1.0);
	glPushMatrix();
	glTranslated(-0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	//pés
	glColor3f(1.0, 0.0, 1.0);
	glPushMatrix();
	glTranslated(-0.20, -0.50, 0.15);
	glScaled(1.0, 0.60, 1.50);
	glutSolidSphere(.1, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.20, -0.485, 0.0);
	glScaled(1.0, 0.65, 1.0);
	glutSolidSphere(.1, 20, 20);
	glPopMatrix();
}
//Perna direita
void rightLeg() {
	glColor3f(0.0, 0.60, 1.0);
	glPushMatrix();
	glTranslated(0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	//pés
	glColor3f(1.0, 0.0, 1.0);
	glPushMatrix();
	glTranslated(0.20, -0.50, 0.15);
	glScaled(1.0, 0.60, 1.50);
	glutSolidSphere(.1, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.20, -0.485, 0.0);
	glScaled(1.0, 0.65, 1.0);
	glutSolidSphere(.1, 20, 20);
	glPopMatrix();
}


void myInit() {
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0 * (64 / 48.0), 2.0 * (64 / 48.0), -2.0, 2.0, 0.1, 100.0); //esquerda, direita, baixo, cima, perto, longe Projeção Paralela
	glViewport(0, 0, 800, 640);

	//Definindo testura
	GLfloat mat_ambient[] = { 0.0f, 0.0f, 1.0f, 1.0f }; 
	GLfloat mat_diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_shininess[] = { 50.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	GLfloat lightIntensity[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_position[] = { 2.0f, 2.0f, 3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

}
//Se nada mais acontecer, faça movimentos de caminhada
void Walk(void)
{
	static float mf = 0.05;	//fator de movimento dos membros

	limbAngle += mf;

	if (limbAngle > 30.0) {
		mf = -0.70;
	}
	if (limbAngle < -30.0) {
		mf = 0.70;
	}
	glutPostRedisplay();
}


void myDisplay(void) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.50, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (walk == true) {
		//Girando em torno do Robo
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		drawRobot();
		glPopMatrix();
		//Movimento de caminhar com o braço esquerdo
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		glTranslated(-0.30, 1.0, 0.0);
		glRotated(limbAngle, 1.0, 0.0, 0.0f);
		glTranslated(0.30, -1.0, 0.0);
		leftArm();
		glPopMatrix();
		//Movimento de andar com o braço direito
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		glTranslated(0.30, 1.0, 0.0);
		glRotated(-limbAngle, 1.0, 0.0, 0.0f);
		glTranslated(-0.30, -1.0, 0.0);
		rightArm();
		glPopMatrix();
		//Movimento de andar com a perna esquerda
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		glRotated(-limbAngle, 1.0, 0.0, 0.0f);
		leftLeg();
		glPopMatrix();
		//Movimento de andar com a perna direita
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		glRotated(limbAngle, 1.0, 0.0, 0.0f);
		rightLeg();
		glPopMatrix();
	}
	else if (walk == false) {
		//Girando em torno do Robô sem Andar
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		drawRobot();
		leftArm();
		rightArm();
		leftLeg();
		rightLeg();
		glPopMatrix();
	}


	glutSwapBuffers();
}



void myKeyboard(unsigned char key, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	static double zoomFactor = 1.0;	//zoom 
	static double zoomFactor2 = 1.0;

	switch (key)
	{
	case 's':
		if (walk == false) {
			walk = true;
		}
		else if (walk == true) {
			walk = false;
		}
		break;
	case 'z':
		zoomFactor -= 0.02;
		zoomFactor2 += 7.7;
		glViewport(1.0 * zoomFactor2, 1.0 * zoomFactor2, 800 * zoomFactor, 640 * zoomFactor);
		break;
	case 'Z':
		zoomFactor += 0.02;
		zoomFactor2 -= 7.7;
		glViewport(1.0 * zoomFactor2, 1.0 * zoomFactor2, 800 * zoomFactor, 640 * zoomFactor);
		break;
	case 'd':
		vertAngle = 0.0;
		horizAngle = 0.0;
		walk = false;
		break;
	case 'e':
		exit(0);			// fechando o programa
	}

	glutPostRedisplay();		//atualiza a tela
}

void arrowKeyPress(int key, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch (key) {
	case GLUT_KEY_RIGHT:
		horizAngle += 2;
		break;
	case GLUT_KEY_LEFT:
		horizAngle -= 2;
		break;
	case GLUT_KEY_UP:
		vertAngle -= 2;
		break;
	case GLUT_KEY_DOWN:
		vertAngle += 2;
		break;
	}

	glutPostRedisplay();		// redesenha a imagem
}


void main(int argc, char** argv) {

	glutInit(&argc, argv);  //Kit de utilitários OpenGL
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  //buffer duplo para animação
	glutInitWindowSize(800, 640);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Android com 9 articulações");
	glutDisplayFunc(myDisplay);
	glutIdleFunc(Walk);		//Função de caminhada contínua para quando nada mais estiver acontecendo

	glutKeyboardFunc(myKeyboard);	//myKeyboard irá lidar com teclas normais
	glutSpecialFunc(arrowKeyPress);	//arrowKeyPress irá lidar com teclas especiais

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);	

	myInit();
	glutMainLoop();
}