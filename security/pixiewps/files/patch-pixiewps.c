--- pixiewps.c.orig	2019-04-08 08:26:23 UTC
+++ pixiewps.c
@@ -32,6 +32,10 @@
 # include <windows.h>
 #endif
 
+#ifdef __FreeBSD__
+# include <sys/types.h>
+#endif
+
 #ifdef __APPLE__
 # define _DARWIN_C_SOURCE
 #endif
