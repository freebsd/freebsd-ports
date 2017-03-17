--- chrome/browser/task_manager/sampling/task_group.h.orig	2017-03-09 20:04:29 UTC
+++ chrome/browser/task_manager/sampling/task_group.h
@@ -96,9 +96,9 @@ class TaskGroup {
   int nacl_debug_stub_port() const { return nacl_debug_stub_port_; }
 #endif  // !defined(DISABLE_NACL)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int open_fd_count() const { return open_fd_count_; }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   int idle_wakeups_per_second() const { return idle_wakeups_per_second_; }
 
@@ -121,9 +121,9 @@ class TaskGroup {
 
   void OnIdleWakeupsRefreshDone(int idle_wakeups_per_second);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void OnOpenFdCountRefreshDone(int open_fd_count);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   void OnProcessPriorityDone(bool is_backgrounded);
 
@@ -171,10 +171,10 @@ class TaskGroup {
   int nacl_debug_stub_port_;
 #endif  // !defined(DISABLE_NACL)
   int idle_wakeups_per_second_;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // The number of file descriptors currently open by the process.
   int open_fd_count_;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   bool gpu_memory_has_duplicates_;
   bool is_backgrounded_;
 
