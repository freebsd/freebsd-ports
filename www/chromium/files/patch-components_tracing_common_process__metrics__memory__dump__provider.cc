--- components/tracing/common/process_metrics_memory_dump_provider.cc.orig	2017-04-19 19:06:33 UTC
+++ components/tracing/common/process_metrics_memory_dump_provider.cc
@@ -56,7 +56,7 @@ base::LazyInstance<
              std::unique_ptr<ProcessMetricsMemoryDumpProvider>>>::Leaky
     g_dump_providers_map = LAZY_INSTANCE_INITIALIZER;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 const char kClearPeakRssCommand[] = "5";
 
 const uint32_t kMaxLineSize = 4096;
@@ -190,13 +190,13 @@ bool GetResidentSizeFromStatmFile(int fd
   return num_scanned == 1;
 }
 
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 std::unique_ptr<base::ProcessMetrics> CreateProcessMetrics(
     base::ProcessId process) {
   if (process == base::kNullProcessId)
     return base::ProcessMetrics::CreateCurrentProcessMetrics();
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Just pass ProcessId instead of handle since they are the same in linux and
   // android.
   return base::ProcessMetrics::CreateProcessMetrics(process);
@@ -205,7 +205,7 @@ std::unique_ptr<base::ProcessMetrics> Cr
   // additional information like ProcessHandle or port provider.
   NOTREACHED();
   return std::unique_ptr<base::ProcessMetrics>();
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 }
 
 }  // namespace
@@ -217,7 +217,7 @@ uint64_t ProcessMetricsMemoryDumpProvide
 ProcessMetricsMemoryDumpProvider::FactoryFunction
     ProcessMetricsMemoryDumpProvider::factory_for_testing = nullptr;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 // static
 FILE* ProcessMetricsMemoryDumpProvider::proc_smaps_for_testing = nullptr;
@@ -244,7 +244,7 @@ bool ProcessMetricsMemoryDumpProvider::D
     pmd->set_has_process_mmaps();
   return res;
 }
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 bool ProcessMetricsMemoryDumpProvider::DumpProcessMemoryMaps(
@@ -620,7 +620,7 @@ bool ProcessMetricsMemoryDumpProvider::D
 
 #if !defined(OS_IOS)
   peak_rss_bytes = process_metrics_->GetPeakWorkingSetSize();
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (is_rss_peak_resettable_) {
     std::string clear_refs_file =
         "/proc/" +
@@ -670,7 +670,7 @@ bool ProcessMetricsMemoryDumpProvider::D
 void ProcessMetricsMemoryDumpProvider::PollFastMemoryTotal(
     uint64_t* memory_total) {
   *memory_total = 0;
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   int statm_fd = fast_polling_statm_fd_for_testing;
   if (statm_fd == -1) {
     if (!fast_polling_statm_fd_.is_valid()) {
@@ -698,7 +698,7 @@ void ProcessMetricsMemoryDumpProvider::P
 }
 
 void ProcessMetricsMemoryDumpProvider::SuspendFastMemoryPolling() {
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   fast_polling_statm_fd_.reset();
 #endif
 }
