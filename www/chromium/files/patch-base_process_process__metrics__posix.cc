--- base/process/process_metrics_posix.cc.orig	2022-02-07 13:39:41 UTC
+++ base/process/process_metrics_posix.cc
@@ -20,6 +20,8 @@
 
 #if defined(OS_APPLE)
 #include <malloc/malloc.h>
+#elif defined(OS_OPENBSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -136,7 +138,7 @@ size_t ProcessMetrics::GetMallocUsage() {
   return stats.size_in_use;
 #elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
   return GetMallocUsageMallinfo();
-#elif defined(OS_FUCHSIA)
+#elif defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(fuchsia): Not currently exposed. https://crbug.com/735087.
   return 0;
 #endif
