--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc.orig	2018-08-01 00:08:55.000000000 +0200
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc	2018-08-04 21:00:31.567932000 +0200
@@ -16,8 +16,10 @@
 #include "build/build_config.h"
 #include "services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h"
 
+#if !defined(OS_BSD)
 // Symbol with virtual address of the start of ELF header of the current binary.
 extern char __ehdr_start;
+#endif
 
 namespace memory_instrumentation {
 
@@ -101,7 +103,7 @@
   // Build ID is needed to symbolize heap profiles, and is generated only on
   // official builds. Build ID is only added for the current library (chrome)
   // since it is racy to read other libraries which can be unmapped any time.
-#if defined(OFFICIAL_BUILD)
+#if defined(OFFICIAL_BUILD) && !defined(OS_BSD)
   uintptr_t addr = reinterpret_cast<uintptr_t>(&ParseSmapsHeader);
   if (addr >= region->start_address && addr < end_addr) {
     base::Optional<std::string> buildid =
@@ -196,6 +198,9 @@
 // static
 bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
                                  mojom::RawOSMemDump* dump) {
+#if defined(OS_BSD)
+  return false;
+#else
   base::ScopedFD autoclose = OpenStatm(pid);
   int statm_fd = autoclose.get();
 
@@ -221,6 +226,7 @@
   dump->resident_set_kb = process_metrics->GetResidentSetSize() / 1024;
 
   return true;
+#endif
 }
 
 // static
