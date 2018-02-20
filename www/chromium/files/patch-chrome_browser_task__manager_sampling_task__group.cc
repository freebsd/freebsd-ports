--- chrome/browser/task_manager/sampling/task_group.cc.orig	2017-12-15 02:04:10.000000000 +0100
+++ chrome/browser/task_manager/sampling/task_group.cc	2017-12-24 02:18:09.634446000 +0100
@@ -28,9 +28,9 @@
 #if defined(OS_WIN)
     REFRESH_TYPE_START_TIME | REFRESH_TYPE_CPU_TIME |
 #endif  // defined(OS_WIN)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     REFRESH_TYPE_FD_COUNT |
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 #if BUILDFLAG(ENABLE_NACL)
     REFRESH_TYPE_NACL |
 #endif  // BUILDFLAG(ENABLE_NACL)
@@ -103,9 +103,9 @@
       nacl_debug_stub_port_(nacl::kGdbDebugStubPortUnknown),
 #endif  // BUILDFLAG(ENABLE_NACL)
       idle_wakeups_per_second_(-1),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       open_fd_count_(-1),
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
       gpu_memory_has_duplicates_(false),
       is_backgrounded_(false),
       weak_ptr_factory_(this) {
@@ -118,10 +118,10 @@
                    weak_ptr_factory_.GetWeakPtr()),
         base::Bind(&TaskGroup::OnIdleWakeupsRefreshDone,
                    weak_ptr_factory_.GetWeakPtr()),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         base::Bind(&TaskGroup::OnOpenFdCountRefreshDone,
                    weak_ptr_factory_.GetWeakPtr()),
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
         base::Bind(&TaskGroup::OnProcessPriorityDone,
                    weak_ptr_factory_.GetWeakPtr()));
 
@@ -338,14 +338,14 @@
   OnBackgroundRefreshTypeFinished(REFRESH_TYPE_IDLE_WAKEUPS);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void TaskGroup::OnOpenFdCountRefreshDone(int open_fd_count) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
 
   open_fd_count_ = open_fd_count;
   OnBackgroundRefreshTypeFinished(REFRESH_TYPE_FD_COUNT);
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 void TaskGroup::OnProcessPriorityDone(bool is_backgrounded) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
