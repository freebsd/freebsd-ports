--- chrome/browser/task_manager/task_manager_observer.h.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/task_manager/task_manager_observer.h
@@ -42,11 +42,11 @@ enum RefreshType {
   // or backgrounded.
   REFRESH_TYPE_PRIORITY = 1 << 13,
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // For observers interested in getting the number of open file descriptors of
   // processes.
   REFRESH_TYPE_FD_COUNT = 1 << 14,
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   REFRESH_TYPE_MEMORY_STATE = 1 << 15,
   REFRESH_TYPE_KEEPALIVE_COUNT = 1 << 16,
