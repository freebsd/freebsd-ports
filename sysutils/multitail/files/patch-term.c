--- term.c.orig	2014-02-24 14:33:39.000000000 -0500
+++ term.c	2014-02-24 14:35:02.000000000 -0500
@@ -16,8 +16,12 @@
 #include <stropts.h>
 #endif
 #ifndef AIX
+#if defined(__FreeBSD__)
+#include <termios.h>
+#else
 #include <sys/termios.h> /* needed on Solaris 8 */
 #endif
+#endif
 #include <sys/socket.h>
 #include <netinet/in.h>
 
