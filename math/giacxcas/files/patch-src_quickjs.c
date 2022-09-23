--- src/quickjs.c.orig	2021-03-23 12:33:15 UTC
+++ src/quickjs.c
@@ -41,6 +41,8 @@
 #include <malloc/malloc.h>
 #elif defined(__linux__)
 #include <malloc.h>
+#elif defined(__FreeBSD__)
+#include <malloc_np.h>
 #endif
 
 #ifdef EMCC
