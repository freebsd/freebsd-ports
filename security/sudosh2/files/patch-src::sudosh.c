--- src/sudosh.c.orig	Thu May 12 19:37:44 2005
+++ src/sudosh.c	Wed Jun  1 14:05:14 2005
@@ -24,6 +24,9 @@
 #include <unistd.h>
 #include <signal.h>
 #include <pwd.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 
 #include "config.h"
 
@@ -81,6 +84,12 @@
 
 #define WRITE(a, b, c) do_write(a, b, c, __FILE__, __LINE__)
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <libutil.h>
+#endif
+
 static struct termios termorig;
 static struct winsize winorig;
 
@@ -423,17 +432,41 @@
 {
     char *sname;
 
+#ifdef __FreeBSD__
+#define PTYLEN        16
+    char sname_area[PTYLEN];
+    struct termios tt;
+    struct winsize win;
+
+    sname = sname_area;
+    if (tcgetattr(STDIN_FILENO, &tt) == -1) {
+	perror("tcgetattr");
+	return -1;
+    }
+    if (ioctl(STDIN_FILENO, TIOCGWINSZ, &win) == -1) {
+	perror("ioctl");
+	return -1;
+    }
+    if (openpty(&p->mfd, &p->sfd, sname, &tt, &win) == -1) {
+#else
     if ((p->mfd = open("/dev/ptmx", O_RDWR)) == -1) {
 	if ((p->mfd = open("/dev/ptc", O_RDWR)) == -1) {
+#endif
 	    perror("Cannot open cloning master pty");
 	    return -1;
+#ifndef __FreeBSD__
 	}
+#endif
     }
 
+#if !defined(__FreeBSD_version) || (defined(__FreeBSD_version) && __FreeBSD_version >= 500000)
     (void) unlockpt(p->mfd);
     (void) grantpt(p->mfd);
+#endif
 
+#ifndef __FreeBSD__
     sname = (char *) ptsname(p->mfd);
+#endif
 
     if ((p->sfd = open(sname, O_RDWR)) == -1) {
 	perror("open slave pty");
@@ -488,7 +521,10 @@
     for (i = 3; i < 100; ++i)
 	close(i);
 
-#ifdef TCSETS
+#ifdef __FreeBSD__
+    (void) tcsetattr(0, TCSADRAIN, &termorig);
+    (void) login_tty(pst->sfd);
+#else
     (void) ioctl(0, TCSETS, &termorig);
 #endif
     (void) ioctl(0, TIOCSWINSZ, &winorig);
@@ -528,25 +564,32 @@
 {
     static struct termios termnew;
 
-#ifdef TCGETS
+#ifdef __FreeBSD__
+    if (tcgetattr(ttyfd, &termorig) == -1) {
+	perror("tcgetattr failed");
+#else
     if (ioctl(ttyfd, TCGETS, &termorig) == -1) {
 	perror("ioctl TCGETS failed");
+#endif
 	exit(1);
     }
-#endif
 
     if (ioctl(ttyfd, TIOCGWINSZ, &winorig) == -1) {
 	perror("ioctl TIOCGWINSZ failed");
 	exit(1);
     }
 
+#ifdef __FreeBSD__
+    (void) cfmakeraw(&termnew);
+    termnew.c_lflag &= ~ECHO;
+    (void) tcsetattr(ttyfd, TCSAFLUSH, &termnew);
+#else
     termnew.c_cc[VEOF] = 1;
     termnew.c_iflag = BRKINT | ISTRIP | IXON | IXANY;
     termnew.c_oflag = 0;
     termnew.c_cflag = termorig.c_cflag;
     termnew.c_lflag &= ~ECHO;
 
-#ifdef TCSETS
     (void) ioctl(ttyfd, TCSETS, &termnew);
 #endif
 }
@@ -556,7 +599,9 @@
     char s[32];
     char t[32];
     char *sp, *tp;
-#ifdef TCSETS
+#ifdef __FreeBSD__
+    (void) tcsetattr(0, TCSADRAIN, &termorig);
+#else
     (void) ioctl(0, TCSETS, &termorig);
 #endif
 
