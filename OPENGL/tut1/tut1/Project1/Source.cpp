#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265


void drawLine(float x1, float y1, float len, float angle, float& x2, float& y2) {
	float t_radian = angle / 180 * PI;
	y2 = y1 + sin(t_radian) * len;
	x2 = x1 + cos(t_radian) * len;
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void drawTriangle(float x1, float y1, float len, float angle) {
	float x, y,x2,y2;
	drawLine(x1, y1, len, angle, x, y);
	drawLine(x, y, len, 180 - (60-angle), x2, y2);
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();

}

void cau4() {
	for (int i = 0; i < 5; i++) {
		drawTriangle(0, 0, 1, 0 + 72 * i);
		drawTriangle(0, 0, 1, 36 + 72 * i);
	}
}

void cau5() {
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 10; i++) {
			glBegin(GL_POLYGON);
			glVertex2f(-2 + 4.0 / 19 * i * 2, 2-2*j*4.0/19);
			glVertex2f(-2 + 4.0 / 19 * (i * 2 + 1), 2 - 2 * j * 4.0 / 19);
			glVertex2f(-2 + 4.0 / 19 * (i * 2 + 1), 2 - 4.0 / 19 - 2 * j * 4.0 / 19);
			glVertex2f(-2 + 4.0 / 19 * i * 2, 2 - 4.0 / 19 - 2 * j * 4.0 / 19);
			glEnd();
			if (i != 9) {
				glBegin(GL_POLYGON);
				glVertex2f(-2 + 4.0 / 19 * i * 2 + 4.0 / 19, 2 - 4.0 / 19 - 2 * j * 4.0 / 19);
				glVertex2f(-2 + 4.0 / 19 * (i * 2 + 1) + 4.0 / 19, 2 - 4.0 / 19 - 2 * j * 4.0 / 19);
				glVertex2f(-2 + 4.0 / 19 * (i * 2 + 1) + 4.0 / 19, 2 - 4.0 / 19 - 4.0 / 19 - 2 * j * 4.0 / 19);
				glVertex2f(-2 + 4.0 / 19 * i * 2 + 4.0 / 19, 2 - 4.0 / 19 - 4.0 / 19 - 2 * j * 4.0 / 19);
				glEnd();
			}
		}
	}
	int j = 9;
	for (int i = 0; i < 10; i++) {
		glBegin(GL_POLYGON);
		glVertex2f(-2 + 4.0 / 19 * i * 2, 2 - 2 * j * 4.0 / 19);
		glVertex2f(-2 + 4.0 / 19 * (i * 2 + 1), 2 - 2 * j * 4.0 / 19);
		glVertex2f(-2 + 4.0 / 19 * (i * 2 + 1), 2 - 4.0 / 19 - 2 * j * 4.0 / 19);
		glVertex2f(-2 + 4.0 / 19 * i * 2, 2 - 4.0 / 19 - 2 * j * 4.0 / 19);
		glEnd();
	}
}

void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	cau5();
	glFlush();
}

void init() {
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(3);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -1, 1);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("simple");
	glutDisplayFunc(mydisplay);
	init();
	glutMainLoop();
}
