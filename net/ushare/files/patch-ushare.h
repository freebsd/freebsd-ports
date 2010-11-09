--- src/ushare.h.orig	2007-12-09 15:03:36.000000000 +0200
+++ src/ushare.h	2010-11-09 14:31:03.466292203 +0200
@@ -27,6 +27,11 @@
 #include <stdbool.h>
 #include <pthread.h>
 
+#ifdef __FreeBSD__
+#include <stdio.h>
+#include <string.h>
+#endif /* __FreeBSD__ */
+
 #ifdef HAVE_DLNA
 #include <dlna.h>
 #endif /* HAVE_DLNA */
