--- check/alc/test_vtm_rx.c.orig	Tue Jul 22 19:37:39 2003
+++ check/alc/test_vtm_rx.c	Wed Oct 15 17:14:28 2003
@@ -27,6 +27,10 @@
 
 #include <stdio.h>
 
+#ifdef FREEBSD
+#include <sys/types.h>
+#endif
+
 #ifdef WIN32
 #include <winsock2.h>
 #else
