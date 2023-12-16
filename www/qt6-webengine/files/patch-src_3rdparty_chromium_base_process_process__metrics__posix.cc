--- src/3rdparty/chromium/base/process/process_metrics_posix.cc.orig	2022-08-31 12:19:35 UTC
+++ src/3rdparty/chromium/base/process/process_metrics_posix.cc
@@ -20,6 +20,8 @@
 
 #if BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
+#elif BUILDFLAG(IS_OPENBSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -135,7 +137,7 @@ size_t ProcessMetrics::GetMallocUsage() {
   return stats.size_in_use;
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
   return GetMallocUsageMallinfo();
-#elif BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // TODO(fuchsia): Not currently exposed. https://crbug.com/735087.
   return 0;
 #endif
