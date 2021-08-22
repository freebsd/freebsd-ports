--- chrome/browser/task_manager/sampling/task_group.h.orig	2021-07-19 18:45:09 UTC
+++ chrome/browser/task_manager/sampling/task_group.h
@@ -41,7 +41,7 @@ constexpr int kUnsupportedVMRefreshFlags =
     REFRESH_TYPE_WEBCACHE_STATS | REFRESH_TYPE_NETWORK_USAGE |
     REFRESH_TYPE_NACL | REFRESH_TYPE_IDLE_WAKEUPS | REFRESH_TYPE_HANDLES |
     REFRESH_TYPE_START_TIME | REFRESH_TYPE_CPU_TIME | REFRESH_TYPE_PRIORITY |
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
     REFRESH_TYPE_FD_COUNT |
 #endif
     REFRESH_TYPE_HARD_FAULTS;
@@ -147,10 +147,10 @@ class TaskGroup {
   }
 #endif  // BUILDFLAG(ENABLE_NACL)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   int open_fd_count() const { return open_fd_count_; }
   void set_open_fd_count(int open_fd_count) { open_fd_count_ = open_fd_count; }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
 
   int idle_wakeups_per_second() const { return idle_wakeups_per_second_; }
   void set_idle_wakeups_per_second(int idle_wakeups) {
@@ -167,9 +167,9 @@ class TaskGroup {
   void RefreshNaClDebugStubPort(int child_process_unique_id);
   void OnRefreshNaClDebugStubPortDone(int port);
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   void OnOpenFdCountRefreshDone(int open_fd_count);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
 
   void OnCpuRefreshDone(double cpu_usage);
   void OnSwappedMemRefreshDone(int64_t swapped_mem_bytes);
@@ -239,10 +239,10 @@ class TaskGroup {
 #if BUILDFLAG(ENABLE_NACL)
   int nacl_debug_stub_port_;
 #endif  // BUILDFLAG(ENABLE_NACL)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   // The number of file descriptors currently open by the process.
   int open_fd_count_;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   int idle_wakeups_per_second_;
   bool gpu_memory_has_duplicates_;
   bool is_backgrounded_;
