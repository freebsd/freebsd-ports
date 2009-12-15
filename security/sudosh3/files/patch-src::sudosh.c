--- src/sudosh.c.orig	2009-11-27 02:19:58.000000000 -0800
+++ src/sudosh.c	2009-12-14 17:30:23.000000000 -0800
@@ -27,6 +27,13 @@
 
 #define WRITE(a, b, c) do_write(a, b, c, __FILE__, __LINE__)
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <libutil.h>
+#include <sys/param.h>
+#endif
+
 typedef enum {false=0, true=1} bool;
 
 static struct termios termorig;
@@ -443,12 +450,32 @@
 {
 	char *sname;
 
+#ifdef __FreeBSD__
+#define PTYLEN        16
+	char sname_area[PTYLEN];
+	struct termios tt;
+	struct winsize win;
+
+	sname = sname_area;
+	if (tcgetattr(STDIN_FILENO, &tt) == -1) {
+		perror ("tcgetattr");
+		return -1;
+	}
+	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &win) == -1) {
+		perror ("ioctl");
+		return -1;
+	}
+	if (openpty(&p->mfd, &p->sfd, sname, &tt, &win) == -1) {
+#else
 	if ((p->mfd = open ("/dev/ptmx", O_RDWR)) == -1) {
 
 		if ((p->mfd = open ("/dev/ptc", O_RDWR)) == -1) {
+#endif
 			perror ("Cannot open cloning master pty");
 			return -1;
+#ifndef __FreeBSD__
 		}
+#endif
 	}
 
 	(void) unlockpt (p->mfd);
@@ -515,9 +542,14 @@
 	for (i = 3; i < 100; ++i)
 		close (i);
 
+#ifdef __FreeBSD__
+	(void) tcsetattr(0, TCSADRAIN, &termorig);
+	(void) login_tty(pst->sfd);
+#else
 #ifdef TCSETS
 	(void) ioctl (0, TCSETS, &termorig);
 #endif
+#endif
 	(void) ioctl (0, TIOCSWINSZ, &winorig);
 
 	setuid (getuid ());
@@ -671,12 +703,20 @@
 {
 	static struct termios termnew;
 
+#ifdef __FreeBSD__
+  if (tcgetattr(ttyfd, &termorig) == -1)
+    {
+      perror ("tcgetattr failed");
+      exit (EXIT_FAILURE);
+    }
+#else
 #ifdef TCGETS
 	if (ioctl (ttyfd, TCGETS, &termorig) == -1) {
 		perror ("ioctl TCGETS failed");
 		exit (EXIT_FAILURE);
 	}
 #endif
+#endif
 
 	if (ioctl (ttyfd, TIOCGWINSZ, &winorig) == -1) {
 	//	perror ("ioctl TIOCGWINSZ failed");
@@ -685,6 +725,11 @@
 		winorig.ws_col = 80;
 	}
 
+#ifdef __FreeBSD__
+	(void) cfmakeraw(&termnew);
+	termnew.c_lflag &= ~ECHO;
+	(void) tcsetattr(ttyfd, TCSAFLUSH, &termnew);
+#else
 	termnew.c_cc[VEOF] = 1;
 	termnew.c_iflag = BRKINT | ISTRIP | IXON | IXANY;
 	termnew.c_oflag = 0;
@@ -694,13 +739,18 @@
 #ifdef TCSETS
 	(void) ioctl (ttyfd, TCSETS, &termnew);
 #endif
+#endif
 }
 
 static void bye (int signum)
 {
+#ifdef __FreeBSD__
+	(void) tcsetattr(0, TCSADRAIN, &termorig);
+#else
 #ifdef TCSETS
 	(void) ioctl (0, TCSETS, &termorig);
 #endif
+#endif
 
 	close (timing.fd);
 	close (script.fd);
