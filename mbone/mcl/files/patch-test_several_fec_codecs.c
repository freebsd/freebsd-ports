--- check/alc/test_several_fec_codecs.c.orig	Tue Jul 22 19:37:39 2003
+++ check/alc/test_several_fec_codecs.c	Wed Oct 15 17:05:40 2003
@@ -28,6 +28,10 @@
 
 #include <stdio.h>
 
+#ifdef FREEBSD
+#include <sys/types.h>
+#endif
+
 #ifdef WIN32
 #include <winsock2.h>
 #else
