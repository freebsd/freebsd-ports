--- check/alc/test_multi_sessions1.c.orig	Tue Jul 22 19:37:39 2003
+++ check/alc/test_multi_sessions1.c	Wed Oct 15 17:11:53 2003
@@ -24,6 +24,11 @@
  */
 
 #include <stdio.h>
+
+#ifdef FREEBSD
+#include <sys/types.h>
+#endif
+
 #ifdef WIN32
 #include <winsock2.h>
 #else
