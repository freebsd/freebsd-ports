--- check/alc/test_no_tx.c.orig	Tue Jul 22 19:37:39 2003
+++ check/alc/test_no_tx.c	Wed Oct 15 17:10:20 2003
@@ -25,6 +25,10 @@
 
 #include <stdio.h>
 
+#ifdef FREEBSD
+#include <sys/types.h>
+#endif
+
 #ifdef WIN32
 #include <winsock2.h>
 #else
