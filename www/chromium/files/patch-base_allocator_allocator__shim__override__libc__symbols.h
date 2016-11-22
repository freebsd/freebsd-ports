--- base/allocator/allocator_shim_override_libc_symbols.h.orig	2016-08-13 16:23:28.370905000 +0300
+++ base/allocator/allocator_shim_override_libc_symbols.h	2016-08-13 16:23:33.784774000 +0300
@@ -10,7 +10,7 @@
 #endif
 #define BASE_ALLOCATOR_ALLOCATOR_SHIM_OVERRIDE_LIBC_SYMBOLS_H_

-#include <malloc.h>
+#include <stdlib.h>

 #include "base/allocator/allocator_shim_internals.h"

