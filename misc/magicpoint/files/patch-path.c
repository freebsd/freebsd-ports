--- image/path.c.orig	2004-07-28 15:47:31 UTC
+++ image/path.c
@@ -20,7 +20,7 @@
 #if 1 /* SYSV */
 #include <unistd.h>
 #endif
-#ifdef __APPLE__
+#if 1
 #include <stdlib.h>
 #endif
 
