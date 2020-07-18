--- src/quickjs/quickjs.c.orig	2020-06-16 16:17:17 UTC
+++ src/quickjs/quickjs.c
@@ -38,6 +38,8 @@
 #include <malloc/malloc.h>
 #elif defined(__linux__) || defined(__NX__)
 #include <malloc.h>
+#elif defined(__FreeBSD__)
+#include <malloc_np.h>
 #endif
 
 #include "cutils.h"
@@ -1515,7 +1517,7 @@ static inline size_t js_def_malloc_usable_size(void *p
     return _msize(ptr);
 #elif defined(EMSCRIPTEN)
     return 0;
-#elif defined(__linux__) || defined(__NX__)
+#elif defined(__linux__) || defined(__NX__) || defined(__FreeBSD__)
     return malloc_usable_size(ptr);
 #else
     /* change this to `return 0;` if compilation fails */
@@ -1589,7 +1591,7 @@ static const JSMallocFunctions def_malloc_funcs = {
     (size_t (*)(const void *))_msize,
 #elif defined(EMSCRIPTEN)
     NULL,
-#elif defined(__linux__) || defined(__NX__)
+#elif defined(__linux__) || defined(__NX__) || defined(__FreeBSD__)
     (size_t (*)(const void *))malloc_usable_size,
 #else
     /* change this to `NULL,` if compilation fails */
