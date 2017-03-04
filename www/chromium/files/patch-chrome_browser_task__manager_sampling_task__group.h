--- chrome/browser/task_manager/sampling/task_group.h.orig	2017-02-02 02:02:49 UTC
+++ chrome/browser/task_manager/sampling/task_group.h
@@ -91,9 +91,9 @@ class TaskGroup {
   int nacl_debug_stub_port() const { return nacl_debug_stub_port_; }
 #endif  // !defined(DISABLE_NACL)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int open_fd_count() const { return open_fd_count_; }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   int idle_wakeups_per_second() const { return idle_wakeups_per_second_; }
 
@@ -112,9 +112,9 @@ class TaskGroup {
 
   void OnIdleWakeupsRefreshDone(int idle_wakeups_per_second);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void OnOpenFdCountRefreshDone(int open_fd_count);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   void OnProcessPriorityDone(bool is_backgrounded);
 
@@ -159,10 +159,10 @@ class TaskGroup {
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
 
