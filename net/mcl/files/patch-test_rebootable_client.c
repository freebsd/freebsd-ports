--- check/alc/test_rebootable_client.c.orig	Tue Jul 22 19:37:39 2003
+++ check/alc/test_rebootable_client.c	Wed Oct 15 17:18:38 2003
@@ -35,6 +35,10 @@
 #include <stdio.h>
 #include <string.h>
 
+#ifdef FREEBSD
+#include <sys/time.h>
+#endif
+
 #ifdef WIN32
 #include <winsock2.h>
 #else
