--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc.orig	2022-02-28 16:54:41 UTC
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc
@@ -5,7 +5,9 @@
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <stdint.h>
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <sys/prctl.h>
+#endif
 
 #include <memory>
 
@@ -26,8 +28,10 @@
 #include "build/build_config.h"
 #include "services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h"
 
+#if !defined(OS_BSD)
 // Symbol with virtual address of the start of ELF header of the current binary.
 extern char __ehdr_start;
+#endif
 
 namespace memory_instrumentation {
 
@@ -39,6 +43,7 @@ using mojom::VmRegionPtr;
 const char kClearPeakRssCommand[] = "5";
 const uint32_t kMaxLineSize = 4096;
 
+#if !defined(OS_BSD)
 // TODO(chiniforooshan): Many of the utility functions in this anonymous
 // namespace should move to base/process/process_metrics_linux.cc to make the
 // code a lot cleaner.  However, we should do so after we made sure the metrics
@@ -267,6 +272,7 @@ class ScopedProcessSetDumpable {
 
   bool was_dumpable_;
 };
+#endif
 
 }  // namespace
 
@@ -280,6 +286,9 @@ void OSMetrics::SetProcSmapsForTesting(FILE* f) {
 // static
 bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
                                  mojom::RawOSMemDump* dump) {
+#if defined(OS_BSD)
+  return false;
+#else
   // TODO(chiniforooshan): There is no need to read both /statm and /status
   // files. Refactor to get everything from /status using ProcessMetric.
   auto statm_file = GetProcPidDir(pid).Append("statm");
@@ -336,10 +345,12 @@ bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
 #endif  //  BUILDFLAG(IS_ANDROID)
 
   return true;
+#endif
 }
 
 // static
 std::vector<VmRegionPtr> OSMetrics::GetProcessMemoryMaps(base::ProcessId pid) {
+#if !defined(OS_BSD)
   std::vector<VmRegionPtr> maps;
   uint32_t res = 0;
   if (g_proc_smaps_for_testing) {
@@ -357,8 +368,13 @@ std::vector<VmRegionPtr> OSMetrics::GetProcessMemoryMa
     return std::vector<VmRegionPtr>();
 
   return maps;
+#else
+    NOTIMPLEMENTED();
+    return std::vector<VmRegionPtr>();
+#endif
 }
 
+#if !defined(OS_BSD) 
 // static
 OSMetrics::MappedAndResidentPagesDumpState OSMetrics::GetMappedAndResidentPages(
     const size_t start_address,
@@ -446,5 +462,6 @@ size_t OSMetrics::GetPeakResidentSetSize(base::Process
   }
   return 0;
 }
+#endif
 
 }  // namespace memory_instrumentation
