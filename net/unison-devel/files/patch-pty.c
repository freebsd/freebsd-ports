--- pty.c.orig	Sun Jan 23 19:55:28 2005
+++ pty.c	Sun Jan 23 19:56:28 2005
@@ -32,6 +32,10 @@
 #ifdef __APPLE__
 #include <util.h>          // openpty
 #endif
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <libutil.h>
+#endif
 
 /* c_openpty: unit -> (int * Unix.file_descr) */
 CAMLprim value c_openpty() {
