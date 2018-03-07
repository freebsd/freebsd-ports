--- chrome/browser/task_manager/sampling/task_group.h.orig	2018-02-24 16:25:10.000000000 +0100
+++ chrome/browser/task_manager/sampling/task_group.h	2018-03-03 21:51:35.928601000 +0100
@@ -106,9 +106,9 @@
   int nacl_debug_stub_port() const { return nacl_debug_stub_port_; }
 #endif  // BUILDFLAG(ENABLE_NACL)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int open_fd_count() const { return open_fd_count_; }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   int idle_wakeups_per_second() const { return idle_wakeups_per_second_; }
 
@@ -122,9 +122,9 @@
   void RefreshNaClDebugStubPort(int child_process_unique_id);
   void OnRefreshNaClDebugStubPortDone(int port);
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void OnOpenFdCountRefreshDone(int open_fd_count);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   void OnCpuRefreshDone(double cpu_usage);
   void OnMemoryUsageRefreshDone(MemoryUsageStats memory_usage);
@@ -184,10 +184,10 @@
 #if BUILDFLAG(ENABLE_NACL)
   int nacl_debug_stub_port_;
 #endif  // BUILDFLAG(ENABLE_NACL)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // The number of file descriptors currently open by the process.
   int open_fd_count_;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   int idle_wakeups_per_second_;
   bool gpu_memory_has_duplicates_;
   bool is_backgrounded_;
