--- components/tracing/common/process_metrics_memory_dump_provider.cc.orig	2017-08-03 00:05:11.000000000 +0200
+++ components/tracing/common/process_metrics_memory_dump_provider.cc	2017-08-10 15:54:41.312710000 +0200
@@ -57,7 +57,7 @@
              std::unique_ptr<ProcessMetricsMemoryDumpProvider>>>::Leaky
     g_dump_providers_map = LAZY_INSTANCE_INITIALIZER;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 const char kClearPeakRssCommand[] = "5";
 
 const uint32_t kMaxLineSize = 4096;
@@ -194,13 +194,13 @@
   return num_scanned == 2;
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
@@ -209,7 +209,7 @@
   // additional information like ProcessHandle or port provider.
   NOTREACHED();
   return std::unique_ptr<base::ProcessMetrics>();
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 }
 
 }  // namespace
@@ -221,7 +221,7 @@
 ProcessMetricsMemoryDumpProvider::FactoryFunction
     ProcessMetricsMemoryDumpProvider::factory_for_testing = nullptr;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 // static
 FILE* ProcessMetricsMemoryDumpProvider::proc_smaps_for_testing = nullptr;
@@ -248,7 +248,7 @@
     pmd->set_has_process_mmaps();
   return res;
 }
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 bool ProcessMetricsMemoryDumpProvider::DumpProcessMemoryMaps(
@@ -637,7 +637,7 @@
 
   uint64_t peak_rss_bytes = 0;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || !defined(OS_BSD)
   base::trace_event::ProcessMemoryTotals::PlatformPrivateFootprint footprint;
 
   base::ScopedFD autoclose;
@@ -673,7 +673,7 @@
 
 #if !defined(OS_IOS)
   peak_rss_bytes = process_metrics_->GetPeakWorkingSetSize();
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (is_rss_peak_resettable_) {
     std::string clear_refs_file =
         "/proc/" +
@@ -714,7 +714,7 @@
   return true;
 }
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 base::ScopedFD ProcessMetricsMemoryDumpProvider::OpenStatm() {
   std::string name =
       "/proc/" +
@@ -725,12 +725,12 @@
   DCHECK(fd.is_valid());
   return fd;
 }
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 void ProcessMetricsMemoryDumpProvider::PollFastMemoryTotal(
     uint64_t* memory_total) {
   *memory_total = 0;
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
   int statm_fd = fast_polling_statm_fd_for_testing;
   if (statm_fd == -1) {
@@ -755,7 +755,7 @@
 }
 
 void ProcessMetricsMemoryDumpProvider::SuspendFastMemoryPolling() {
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   fast_polling_statm_fd_.reset();
 #endif
 }
