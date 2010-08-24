--- xvt/ttyinit.c.orig	2010-08-24 07:28:17.000000000 +0000
+++ xvt/ttyinit.c	2010-08-24 07:31:01.000000000 +0000
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
@@ -398,7 +403,7 @@
  */
 static char* get_pseudo_tty(int* pmaster, int* pslave)
 {
-#ifdef BSD_PTY
+#if defined(BSD_PTY) || defined(__FreeBSD__)
     int mfd, sfd;
     char *s3, *s4;
     static char ptyc3[] = "pqrstuvwxyz";
