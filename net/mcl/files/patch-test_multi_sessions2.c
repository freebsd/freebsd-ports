--- check/alc/test_multi_sessions2.c.orig	Tue Jul 22 19:37:39 2003
+++ check/alc/test_multi_sessions2.c	Wed Oct 15 17:12:13 2003
@@ -25,6 +25,11 @@
  */
 
 #include <stdio.h>
+
+#ifdef FREEBSD
+#include <sys/types.h>
+#endif
+
 #ifdef WIN32
 #include <winsock2.h>
 #include <io.h>
