--- base/allocator/allocator_shim_override_libc_symbols.h.orig	2017-04-19 19:06:28 UTC
+++ base/allocator/allocator_shim_override_libc_symbols.h
@@ -10,7 +10,7 @@
 #endif
 #define BASE_ALLOCATOR_ALLOCATOR_SHIM_OVERRIDE_LIBC_SYMBOLS_H_
 
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "base/allocator/allocator_shim_internals.h"
 
