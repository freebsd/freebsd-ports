--- netadm/rpc.c	2008-01-27 16:29:09.000000000 +0100
+++ netadm/rpc.c	2008-01-27 16:34:49.000000000 +0100
@@ -35,7 +35,9 @@
 
 #include <stdio.h>
 
-#ifdef SYS_V
+#ifdef __FreeBSD__
+#include <termios.h>
+#elif defined(SYS_V)
 #include <termio.h>
 #else
 #ifndef _WIN32
@@ -749,7 +751,9 @@
 {
 
 #ifndef _WIN32
-#ifdef	SYS_V
+#ifdef __FreeBSD__
+	struct	termios	tio;
+#elif defined(SYS_V)
 	struct	termio	tio;
 #else
 	struct	sgttyb	sg;
@@ -762,7 +766,11 @@
 
 	fd = fileno(rfp);
 
-#ifdef	SYS_V
+#ifdef __FreeBSD__
+	tcgetattr(fd, &tio);
+	tio.c_lflag &= ~(ECHO);
+	tcsetattr(fd, TCSANOW, &tio);
+#elif defined(SYS_V)
 	(void)ioctl(fd, (int)TCGETA, &tio);
 	tio.c_lflag &= ~(ECHO);
 	(void)ioctl(fd, (int)TCSETA, &tio);
@@ -779,7 +787,9 @@
 void devttyecho()		/* turn echo on */
 {
 #ifndef _WIN32
-#ifdef	SYS_V
+#ifdef __FreeBSD__
+	struct	termios	tio;
+#elif defined(SYS_V)
 	struct	termio	tio;
 #else
 	struct	sgttyb	sg;
@@ -792,7 +802,11 @@
 
 	fd = fileno(rfp);
 
-#ifdef	SYS_V
+#ifdef __FreeBSD__
+	tcgetattr(fd, &tio);
+	tio.c_lflag |= ECHO;
+	tcsetattr(fd, TCSANOW, &tio);
+#elif defined(SYS_V)
 	(void)ioctl(fd, (int)TCGETA, &tio);
 	tio.c_lflag |= ECHO;
 	(void)ioctl(fd, (int)TCSETA, &tio);
