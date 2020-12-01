--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc.orig	2020-11-13 06:36:46 UTC
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc
@@ -5,7 +5,6 @@
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <stdint.h>
-#include <sys/prctl.h>
 
 #include <memory>
 
@@ -25,8 +24,14 @@
 #include "build/build_config.h"
 #include "services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h"
 
+#if !defined(OS_BSD)
+#include <sys/prctl.h>
+#endif
+
+#if !defined(OS_BSD)
 // Symbol with virtual address of the start of ELF header of the current binary.
 extern char __ehdr_start;
+#endif
 
 namespace memory_instrumentation {
 
@@ -89,6 +94,7 @@ struct ModuleData {
 
 ModuleData GetMainModuleData() {
   ModuleData module_data;
+#if !defined(OS_BSD)
   Dl_info dl_info;
   if (dladdr(&__ehdr_start, &dl_info)) {
     base::debug::ElfBuildIdBuffer build_id;
@@ -99,6 +105,7 @@ ModuleData GetMainModuleData() {
       module_data.build_id = std::string(build_id, build_id_length);
     }
   }
+#endif
   return module_data;
 }
 
@@ -146,14 +153,14 @@ bool ParseSmapsHeader(const char* header_line,
   // Build ID is needed to symbolize heap profiles, and is generated only on
   // official builds. Build ID is only added for the current library (chrome)
   // since it is racy to read other libraries which can be unmapped any time.
-#if defined(OFFICIAL_BUILD)
+#if defined(OFFICIAL_BUILD) && !defined(OS_BSD)
   if (!region->mapped_file.empty() &&
       base::StartsWith(main_module_data.path, region->mapped_file,
                        base::CompareCase::SENSITIVE) &&
       !main_module_data.build_id.empty()) {
     region->module_debugid = main_module_data.build_id;
   }
-#endif  // defined(OFFICIAL_BUILD)
+#endif  // defined(OFFICIAL_BUILD) && !defined(OS_BSD)
 
   return res;
 }
@@ -236,6 +243,7 @@ uint32_t ReadLinuxProcSmapsFile(FILE* smaps_file,
 class ScopedProcessSetDumpable {
  public:
   ScopedProcessSetDumpable() {
+#if !defined(OS_BSD)
     int result = prctl(PR_GET_DUMPABLE, 0, 0, 0, 0);
     if (result < 0) {
       PLOG(ERROR) << "prctl";
@@ -251,15 +259,20 @@ class ScopedProcessSetDumpable {
         AvoidPrctlOnDestruction();
       }
     }
+#else
+    was_dumpable_ = true;
+#endif
   }
 
   ScopedProcessSetDumpable(const ScopedProcessSetDumpable&) = delete;
   ScopedProcessSetDumpable& operator=(const ScopedProcessSetDumpable&) = delete;
 
   ~ScopedProcessSetDumpable() {
+#if !defined(OS_BSD)
     if (!was_dumpable_) {
       PCHECK(prctl(PR_SET_DUMPABLE, 0, 0, 0, 0) == 0) << "prctl";
     }
+#endif
   }
 
  private:
@@ -282,6 +295,7 @@ bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
                                  mojom::RawOSMemDump* dump) {
   // TODO(chiniforooshan): There is no need to read both /statm and /status
   // files. Refactor to get everything from /status using ProcessMetric.
+#if !defined(OS_BSD)
   auto statm_file = GetProcPidDir(pid).Append("statm");
   auto autoclose = base::ScopedFD(open(statm_file.value().c_str(), O_RDONLY));
   int statm_fd = autoclose.get();
@@ -296,6 +310,10 @@ bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
 
   if (!success)
     return false;
+#else
+  uint64_t resident_pages = 0;
+  uint64_t shared_pages = 0;
+#endif
 
   auto process_metrics = CreateProcessMetrics(pid);
 
@@ -340,6 +358,10 @@ bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
 
 // static
 std::vector<VmRegionPtr> OSMetrics::GetProcessMemoryMaps(base::ProcessId pid) {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+  return std::vector<VmRegionPtr>();
+#else
   std::vector<VmRegionPtr> maps;
   uint32_t res = 0;
   if (g_proc_smaps_for_testing) {
@@ -357,6 +379,7 @@ std::vector<VmRegionPtr> OSMetrics::GetProcessMemoryMa
     return std::vector<VmRegionPtr>();
 
   return maps;
+#endif
 }
 
 // static
@@ -364,6 +387,10 @@ OSMetrics::MappedAndResidentPagesDumpState OSMetrics::
     const size_t start_address,
     const size_t end_address,
     std::vector<uint8_t>* accessed_pages_bitmap) {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+  return OSMetrics::MappedAndResidentPagesDumpState::kFailure;
+#else
   const char* kPagemap = "/proc/self/pagemap";
 
   base::ScopedFILE pagemap_file(fopen(kPagemap, "r"));
@@ -411,6 +438,7 @@ OSMetrics::MappedAndResidentPagesDumpState OSMetrics::
     }
   }
   return OSMetrics::MappedAndResidentPagesDumpState::kSuccess;
+#endif
 }
 
 // static
