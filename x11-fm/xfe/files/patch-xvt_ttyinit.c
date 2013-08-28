--- xvt/ttyinit.c.orig	2013-08-13 17:49:45.000000000 +0200
+++ xvt/ttyinit.c	2013-08-26 17:37:10.000000000 +0200
@@ -37,7 +37,6 @@
 #include <unistd.h>
 #include <signal.h>
 #include <fcntl.h>
-#include <utmp.h>
 #include <sys/param.h>
 #if __FreeBSD_version >= 900007
 #    include <utmpx.h>
@@ -394,7 +393,6 @@
 static char* get_pseudo_tty(int* pmaster, int* pslave)
 {
     int mfd = 0, sfd = 0;
-    char *ttynam = NULL;
 #if defined(BSD_PTY) || defined(__FreeBSD__)
     char *s3, *s4;
     static char ptyc3[] = "pqrstuvwxyz";
@@ -435,7 +433,9 @@
         error("could not open slave tty %s",ttynam);
         return(NULL);
     }
-#endif /* BSD_PTY */
+#else /* BSD_PTY */
+    char *ttynam = NULL;
+#endif
 
 #ifdef SVR4_PTY
 
