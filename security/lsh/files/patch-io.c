--- src/io.c.orig	Sun Feb 16 20:46:23 2003
+++ src/io.c	Sun Mar  2 10:11:18 2003
@@ -34,7 +34,11 @@
 #endif
 
 /* For the popen code */
+#ifdef __FreeBSD__
+#include <sys/wait.h>
+#else
 #include <wait.h>
+#endif
 
 #ifdef HAVE_POLL
 # if HAVE_POLL_H
