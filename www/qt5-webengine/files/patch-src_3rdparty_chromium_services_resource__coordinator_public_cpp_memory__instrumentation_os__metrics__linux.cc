--- src/3rdparty/chromium/services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc
@@ -5,7 +5,6 @@
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <stdint.h>
-#include <sys/prctl.h>
 
 #include <memory>
 
@@ -27,8 +26,14 @@
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
 
@@ -91,6 +96,7 @@ ModuleData GetMainModuleData() {
 
 ModuleData GetMainModuleData() {
   ModuleData module_data;
+#if !defined(OS_BSD)
   Dl_info dl_info;
   if (dladdr(&__ehdr_start, &dl_info)) {
     base::debug::ElfBuildIdBuffer build_id;
@@ -101,6 +107,7 @@ ModuleData GetMainModuleData() {
       module_data.build_id = std::string(build_id, build_id_length);
     }
   }
+#endif
   return module_data;
 }
 
@@ -148,14 +155,14 @@ bool ParseSmapsHeader(const char* header_line,
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
@@ -238,6 +245,7 @@ class ScopedProcessSetDumpable {
 class ScopedProcessSetDumpable {
  public:
   ScopedProcessSetDumpable() {
+#if !defined(OS_BSD)
     int result = prctl(PR_GET_DUMPABLE, 0, 0, 0, 0);
     if (result < 0) {
       PLOG(ERROR) << "prctl";
@@ -253,15 +261,20 @@ class ScopedProcessSetDumpable {
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
@@ -284,6 +297,7 @@ bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
                                  mojom::RawOSMemDump* dump) {
   // TODO(chiniforooshan): There is no need to read both /statm and /status
   // files. Refactor to get everything from /status using ProcessMetric.
+#if !defined(OS_BSD)
   auto statm_file = GetProcPidDir(pid).Append("statm");
   auto autoclose = base::ScopedFD(open(statm_file.value().c_str(), O_RDONLY));
   int statm_fd = autoclose.get();
@@ -298,6 +312,10 @@ bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
 
   if (!success)
     return false;
+#else
+  uint64_t resident_pages = 0;
+  uint64_t shared_pages = 0;
+#endif
 
   auto process_metrics = CreateProcessMetrics(pid);
 
@@ -342,6 +360,10 @@ std::vector<VmRegionPtr> OSMetrics::GetProcessMemoryMa
 
 // static
 std::vector<VmRegionPtr> OSMetrics::GetProcessMemoryMaps(base::ProcessId pid) {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+  return std::vector<VmRegionPtr>();
+#else
   std::vector<VmRegionPtr> maps;
   uint32_t res = 0;
   if (g_proc_smaps_for_testing) {
@@ -359,6 +381,7 @@ std::vector<VmRegionPtr> OSMetrics::GetProcessMemoryMa
     return std::vector<VmRegionPtr>();
 
   return maps;
+#endif
 }
 
 // static
@@ -366,6 +389,10 @@ OSMetrics::MappedAndResidentPagesDumpState OSMetrics::
     const size_t start_address,
     const size_t end_address,
     std::vector<uint8_t>* accessed_pages_bitmap) {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+  return OSMetrics::MappedAndResidentPagesDumpState::kFailure;
+#else
   const char* kPagemap = "/proc/self/pagemap";
 
   base::ScopedFILE pagemap_file(fopen(kPagemap, "r"));
@@ -413,6 +440,7 @@ OSMetrics::MappedAndResidentPagesDumpState OSMetrics::
     }
   }
   return OSMetrics::MappedAndResidentPagesDumpState::kSuccess;
+#endif
 }
 
 // static
