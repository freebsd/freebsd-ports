--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc.orig	2017-09-05 21:05:23.000000000 +0200
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc	2017-09-09 15:42:00.563572000 +0200
@@ -15,6 +15,11 @@
 #include "build/build_config.h"
 #include "services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h"
 
+#if defined(OS_BSD)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 namespace memory_instrumentation {
 
 namespace {
@@ -201,7 +206,15 @@
 
   const static size_t page_size = base::GetPageSize();
   uint64_t rss_anon_bytes = (resident_pages - shared_pages) * page_size;
+#if defined(OS_BSD)
+  uint64_t retval;
+  size_t size = sizeof(retval);
+
+  sysctlbyname("vm.swap_total", &retval, &size, NULL, 0);
+  uint64_t vm_swap_bytes = retval;
+#else
   uint64_t vm_swap_bytes = process_metrics->GetVmSwapBytes();
+#endif
 
   dump->platform_private_footprint.rss_anon_bytes = rss_anon_bytes;
   dump->platform_private_footprint.vm_swap_bytes = vm_swap_bytes;
