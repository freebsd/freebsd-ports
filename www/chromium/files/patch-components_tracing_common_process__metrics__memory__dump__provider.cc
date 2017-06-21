--- components/tracing/common/process_metrics_memory_dump_provider.cc.orig	2017-06-05 19:03:06 UTC
+++ components/tracing/common/process_metrics_memory_dump_provider.cc
@@ -57,7 +57,7 @@ base::LazyInstance<
              std::unique_ptr<ProcessMetricsMemoryDumpProvider>>>::Leaky
     g_dump_providers_map = LAZY_INSTANCE_INITIALIZER;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 const char kClearPeakRssCommand[] = "5";
 
 const uint32_t kMaxLineSize = 4096;
@@ -191,13 +191,13 @@ bool GetResidentSizeFromStatmFile(int fd, uint64_t* re
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
@@ -206,7 +206,7 @@ std::unique_ptr<base::ProcessMetrics> CreateProcessMet
   // additional information like ProcessHandle or port provider.
   NOTREACHED();
   return std::unique_ptr<base::ProcessMetrics>();
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 }
 
 }  // namespace
@@ -218,7 +218,7 @@ uint64_t ProcessMetricsMemoryDumpProvider::rss_bytes_f
 ProcessMetricsMemoryDumpProvider::FactoryFunction
     ProcessMetricsMemoryDumpProvider::factory_for_testing = nullptr;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 // static
 FILE* ProcessMetricsMemoryDumpProvider::proc_smaps_for_testing = nullptr;
@@ -245,7 +245,7 @@ bool ProcessMetricsMemoryDumpProvider::DumpProcessMemo
     pmd->set_has_process_mmaps();
   return res;
 }
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 bool ProcessMetricsMemoryDumpProvider::DumpProcessMemoryMaps(
@@ -628,7 +628,7 @@ bool ProcessMetricsMemoryDumpProvider::DumpProcessTota
 
 #if !defined(OS_IOS)
   peak_rss_bytes = process_metrics_->GetPeakWorkingSetSize();
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (is_rss_peak_resettable_) {
     std::string clear_refs_file =
         "/proc/" +
@@ -672,7 +672,7 @@ bool ProcessMetricsMemoryDumpProvider::DumpProcessTota
 void ProcessMetricsMemoryDumpProvider::PollFastMemoryTotal(
     uint64_t* memory_total) {
   *memory_total = 0;
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   int statm_fd = fast_polling_statm_fd_for_testing;
   if (statm_fd == -1) {
     if (!fast_polling_statm_fd_.is_valid()) {
@@ -700,7 +700,7 @@ void ProcessMetricsMemoryDumpProvider::PollFastMemoryT
 }
 
 void ProcessMetricsMemoryDumpProvider::SuspendFastMemoryPolling() {
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   fast_polling_statm_fd_.reset();
 #endif
 }
