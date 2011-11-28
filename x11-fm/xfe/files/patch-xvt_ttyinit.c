--- xvt/ttyinit.c.orig	2010-09-15 16:32:26.000000000 +0200
+++ xvt/ttyinit.c	2011-11-28 12:45:51.000000000 +0100
@@ -37,7 +37,12 @@
 #include <unistd.h>
 #include <signal.h>
 #include <fcntl.h>
-#include <utmp.h>
+#include <sys/param.h>
+#if __FreeBSD_version >= 900007
+#    include <utmpx.h>
+#else
+#    include <utmp.h>
+#endif
 #include <grp.h>
 #include <pwd.h>
 #include <errno.h>
@@ -175,7 +180,9 @@
 #ifdef BSD_UTMP
 static int tslot = -1;		/* index to our slot in the utmp file */
 #endif /* BSD_UTMP */
+#if defined(BSD_UTMP) || defined(SVR4_UTMP)
 static struct utmp utent;	/* our current utmp entry */
+#endif
 
 /*  Catch a SIGCHLD signal and exit if the direct child has died.
  */
@@ -385,7 +392,7 @@
  */
 static char* get_pseudo_tty(int* pmaster, int* pslave)
 {
-#ifdef BSD_PTY
+#if defined(BSD_PTY) || defined(__FreeBSD__)
     int mfd, sfd;
     char *s3, *s4;
     static char ptyc3[] = "pqrstuvwxyz";
