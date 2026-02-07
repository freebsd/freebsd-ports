--- src/quickjs.c.orig	2021-03-23 12:33:15 UTC
+++ src/quickjs.c
@@ -34,13 +34,15 @@
 #ifdef NSPIRE_NEWLIB
 #include "fenv.h"
 #else
-#include <fenv.h>
+#include </usr/include/fenv.h>
 #endif
 #include <math.h>
 #if defined(__APPLE__)
 #include <malloc/malloc.h>
 #elif defined(__linux__)
 #include <malloc.h>
+#elif defined(__FreeBSD__)
+#include <malloc_np.h>
 #endif
 
 #ifdef EMCC
