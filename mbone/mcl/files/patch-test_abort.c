--- check/alc/test_abort.c.orig	Tue Jul 22 19:37:39 2003
+++ check/alc/test_abort.c	Wed Oct 15 17:10:42 2003
@@ -26,6 +26,10 @@
 #include <stdio.h>
 #include <stdlib.h>			/* for exit */
 
+#ifdef FREEBSD
+#include <sys/types.h>
+#endif
+
 #ifdef WIN32
 #include <winsock2.h>
 #include <io.h>
