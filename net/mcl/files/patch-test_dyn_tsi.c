--- check/alc/test_dyn_tsi.c.orig	Tue Jul 22 19:37:39 2003
+++ check/alc/test_dyn_tsi.c	Wed Oct 15 17:13:37 2003
@@ -30,6 +30,10 @@
 
 #include <stdio.h>
 
+#ifdef FREEBSD
+#include <sys/types.h>
+#endif
+
 #ifdef WIN32
 #include <winsock2.h>
 #else
