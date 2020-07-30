--- base/process/process_metrics_posix.cc.orig	2020-07-07 21:57:30 UTC
+++ base/process/process_metrics_posix.cc
@@ -20,6 +20,8 @@
 
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
+#elif defined(OS_FREEBSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -126,7 +128,7 @@ size_t ProcessMetrics::GetMallocUsage() {
 #else
   return minfo.hblkhd + minfo.arena;
 #endif
-#elif defined(OS_FUCHSIA)
+#elif defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(fuchsia): Not currently exposed. https://crbug.com/735087.
   return 0;
 #endif
