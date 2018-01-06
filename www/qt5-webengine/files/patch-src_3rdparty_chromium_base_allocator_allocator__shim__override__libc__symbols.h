--- src/3rdparty/chromium/base/allocator/allocator_shim_override_libc_symbols.h.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/allocator/allocator_shim_override_libc_symbols.h
@@ -10,7 +10,7 @@
 #endif
 #define BASE_ALLOCATOR_ALLOCATOR_SHIM_OVERRIDE_LIBC_SYMBOLS_H_
 
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "base/allocator/allocator_shim_internals.h"
 
