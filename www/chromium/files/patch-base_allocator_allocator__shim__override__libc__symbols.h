--- base/allocator/allocator_shim_override_libc_symbols.h.orig	2021-04-14 18:40:48 UTC
+++ base/allocator/allocator_shim_override_libc_symbols.h
@@ -16,6 +16,10 @@
 #include <malloc.h>
 #endif
 
+#if defined(OS_BSD)
+#include <stdlib.h>
+#endif
+
 #include "base/allocator/allocator_shim_internals.h"
 
 extern "C" {
