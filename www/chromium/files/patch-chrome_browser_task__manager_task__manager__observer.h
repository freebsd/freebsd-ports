--- chrome/browser/task_manager/task_manager_observer.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/task_manager/task_manager_observer.h
@@ -47,7 +47,7 @@ enum RefreshType {
   // or backgrounded.
   REFRESH_TYPE_PRIORITY = 1 << 13,
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   // For observers interested in getting the number of open file descriptors of
   // processes.
   REFRESH_TYPE_FD_COUNT = 1 << 14,
