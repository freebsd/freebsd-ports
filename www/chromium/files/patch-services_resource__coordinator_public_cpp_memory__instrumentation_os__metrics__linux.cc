--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc.orig	2019-04-30 22:22:56 UTC
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc
@@ -19,8 +19,10 @@
 #include "build/build_config.h"
 #include "services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h"
 
+#if !defined(OS_BSD)
 // Symbol with virtual address of the start of ELF header of the current binary.
 extern char __ehdr_start;
+#endif
 
 namespace memory_instrumentation {
 
@@ -69,6 +71,7 @@ struct ModuleData {
 
 ModuleData GetMainModuleData() {
   ModuleData module_data;
+#if !defined(OS_BSD)
   Dl_info dl_info;
   if (dladdr(&__ehdr_start, &dl_info)) {
     base::debug::ElfBuildIdBuffer build_id;
@@ -79,6 +82,7 @@ ModuleData GetMainModuleData() {
       module_data.build_id = std::string(build_id, build_id_length);
     }
   }
+#endif
   return module_data;
 }
 
@@ -126,14 +130,14 @@ bool ParseSmapsHeader(const char* header_line,
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
@@ -220,6 +224,10 @@ void OSMetrics::SetProcSmapsForTesting(FILE* f) {
 // static
 bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
                                  mojom::RawOSMemDump* dump) {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+  return false;
+#else
   base::ScopedFD autoclose = OpenStatm(pid);
   int statm_fd = autoclose.get();
 
@@ -267,10 +275,15 @@ bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
 #endif  //  defined(OS_ANDROID)
 
   return true;
+#endif
 }
 
 // static
 std::vector<VmRegionPtr> OSMetrics::GetProcessMemoryMaps(base::ProcessId pid) {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+  return std::vector<VmRegionPtr>();
+#else
   std::vector<VmRegionPtr> maps;
   uint32_t res = 0;
   if (g_proc_smaps_for_testing) {
@@ -288,6 +301,7 @@ std::vector<VmRegionPtr> OSMetrics::GetProcessMemoryMa
     return std::vector<VmRegionPtr>();
 
   return maps;
+#endif
 }
 
 // static
@@ -295,6 +309,10 @@ OSMetrics::MappedAndResidentPagesDumpState OSMetrics::
     const size_t start_address,
     const size_t end_address,
     std::vector<uint8_t>* accessed_pages_bitmap) {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+  return OSMetrics::MappedAndResidentPagesDumpState::kFailure;
+#else
   const char* kPagemap = "/proc/self/pagemap";
 
   base::ScopedFILE pagemap_file(fopen(kPagemap, "r"));
@@ -336,6 +354,7 @@ OSMetrics::MappedAndResidentPagesDumpState OSMetrics::
     }
   }
   return OSMetrics::MappedAndResidentPagesDumpState::kSuccess;
+#endif
 }
 
 }  // namespace memory_instrumentation
