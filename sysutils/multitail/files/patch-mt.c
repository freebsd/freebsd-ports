--- mt.c.orig	2014-02-16 09:06:54.000000000 -0500
+++ mt.c	2014-02-24 14:35:45.000000000 -0500
@@ -23,8 +23,12 @@
 #include <sys/ioctl.h>
 #include <sys/stat.h>
 #ifndef AIX
+#if defined(__FreeBSD__)
+#include <termios.h>
+#else
 #include <sys/termios.h> /* needed on Solaris 8 */
 #endif
+#endif
 #include <sys/time.h>
 #include <sys/wait.h>
 #include <unistd.h>
