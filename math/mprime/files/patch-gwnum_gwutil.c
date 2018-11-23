--- gwnum/gwutil.c.orig	2016-09-07 01:25:20 UTC
+++ gwnum/gwutil.c
@@ -17,7 +17,7 @@
 #include <malloc.h>
 #include <memory.h>
 #endif
-#ifdef __APPLE__
+#if defined (__APPLE__) || defined (__FreeBSD__)
 #include <memory.h>
 #endif
 #include "gwcommon.h"
