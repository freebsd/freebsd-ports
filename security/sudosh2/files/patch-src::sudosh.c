--- src/sudosh.c.orig	Sun Jun 12 18:13:15 2005
+++ src/sudosh.c	Thu Jun 16 21:02:50 2005
@@ -28,6 +28,13 @@
 
 #define WRITE(a, b, c) do_write(a, b, c, __FILE__, __LINE__)
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <libutil.h>
+#include <sys/param.h>
+#endif
+
 static struct termios termorig;
 static struct winsize winorig;
 
@@ -554,19 +561,43 @@
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
   if ((p->mfd = open ("/dev/ptmx", O_RDWR)) == -1)
     {
       if ((p->mfd = open ("/dev/ptc", O_RDWR)) == -1)
 	{
+#endif
 	  perror ("Cannot open cloning master pty");
 	  return -1;
+#ifdef __FreeBSD
 	}
+#endif
     }
 
+#if !defined(__FreeBSD_version) || (defined(__FreeBSD_version) && __FreeBSD_version >= 500000)
   (void) unlockpt (p->mfd);
   (void) grantpt (p->mfd);
+#endif
 
+#ifndef __FreeBSD
   sname = (char *) ptsname (p->mfd);
+#endif
 
   if ((p->sfd = open (sname, O_RDWR)) == -1)
     {
@@ -628,9 +659,14 @@
   for (i = 3; i < 100; ++i)
     close (i);
 
+#ifdef __FreeBSD__
+    (void) tcsetattr(0, TCSADRAIN, &termorig);
+    (void) login_tty(pst->sfd);
+#else
 #ifdef TCSETS
   (void) ioctl (0, TCSETS, &termorig);
 #endif
+#endif
   (void) ioctl (0, TIOCSWINSZ, &winorig);
 
   setuid (getuid ());
@@ -672,6 +708,13 @@
 {
   static struct termios termnew;
 
+#ifdef __FreeBSD__
+  if (tcgetattr(ttyfd, &termorig) == -1)
+    {
+      perror("tcgetattr failed");
+      exit (EXIT_FAILURE);
+    }
+#else
 #ifdef TCGETS
   if (ioctl (ttyfd, TCGETS, &termorig) == -1)
     {
@@ -679,6 +722,7 @@
       exit (EXIT_FAILURE);
     }
 #endif
+#endif
 
   if (ioctl (ttyfd, TIOCGWINSZ, &winorig) == -1)
     {
@@ -686,6 +730,11 @@
       exit (EXIT_FAILURE);
     }
 
+#ifdef __FreeBSD__
+    (void) cfmakeraw(&termnew);
+    termnew.c_lflag &= ~ECHO;
+    (void) tcsetattr(ttyfd, TCSAFLUSH, &termnew);
+#else
   termnew.c_cc[VEOF] = 1;
   termnew.c_iflag = BRKINT | ISTRIP | IXON | IXANY;
   termnew.c_oflag = 0;
@@ -695,13 +744,19 @@
 #ifdef TCSETS
   (void) ioctl (ttyfd, TCSETS, &termnew);
 #endif
+#endif
 }
 
 static void
 bye (int signum)
 {
+
+#ifdef __FreeBSD__
+    (void) tcsetattr(0, TCSADRAIN, &termorig);
+#else
 #ifdef TCSETS
   (void) ioctl (0, TCSETS, &termorig);
+#endif
 #endif
 
   close (timing.fd);
