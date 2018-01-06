malloc.h does not exist on FreeBSD, and neither do memalign(3) and pvalloc(3).
--- src/core/api/qtbug-61521.cpp
+++ src/core/api/qtbug-61521.cpp
@@ -38,7 +38,7 @@
 ****************************************************************************/
 
 #include <stdlib.h>
-#include <malloc.h>
+#include <unistd.h>
 
 #define SHIM_ALIAS_SYMBOL(fn) __attribute__((weak, alias(#fn)))
 #define SHIM_SYMBOL_VERSION(fn) __asm__(".symver __" #fn "," #fn "@Qt_5")
@@ -66,18 +66,10 @@ SHIM_SYMBOL_VERSION(cfree);
 void __cfree(void* ptr)
     SHIM_ALIAS_SYMBOL(ShimCFree);
 
-SHIM_SYMBOL_VERSION(memalign);
-void* __memalign(size_t align, size_t s)
-    SHIM_ALIAS_SYMBOL(ShimMemalign);
-
 SHIM_SYMBOL_VERSION(valloc);
 void* __valloc(size_t size)
     SHIM_ALIAS_SYMBOL(ShimValloc);
 
-SHIM_SYMBOL_VERSION(pvalloc);
-void* __pvalloc(size_t size)
-    SHIM_ALIAS_SYMBOL(ShimPvalloc);
-
 SHIM_SYMBOL_VERSION(posix_memalign);
 int __posix_memalign(void** r, size_t a, size_t s)
     SHIM_ALIAS_SYMBOL(ShimPosixMemalign);
@@ -102,18 +94,10 @@ SHIM_HIDDEN void ShimCFree(void* ptr) {
     free(ptr);
 }
 
-SHIM_HIDDEN void* ShimMemalign(size_t align, size_t s) {
-    return memalign(align,s);
-}
-
 SHIM_HIDDEN void* ShimValloc(size_t size) {
     return  valloc(size);
 }
 
-SHIM_HIDDEN void* ShimPvalloc(size_t size) {
-    return pvalloc(size);
-}
-
 SHIM_HIDDEN int ShimPosixMemalign(void** r, size_t a, size_t s) {
     return posix_memalign(r,a,s);
 }
