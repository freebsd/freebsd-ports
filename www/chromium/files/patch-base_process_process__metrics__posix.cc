--- base/process/process_metrics_posix.cc.orig	2017-09-05 21:05:11.000000000 +0200
+++ base/process/process_metrics_posix.cc	2017-09-11 19:41:06.103369000 +0200
@@ -16,6 +16,8 @@
 
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
+#elif defined(OS_BSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -103,8 +105,9 @@
 #endif
 #elif defined(OS_FUCHSIA)
   // TODO(fuchsia): Not currently exposed. https://crbug.com/735087.
-  return 0;
+  NOTIMPLEMENTED();
 #endif
+  return 0;
 }
 
 }  // namespace base
