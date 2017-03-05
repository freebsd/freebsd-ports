--- chrome/browser/task_manager/task_manager_observer.h.orig	2017-02-02 02:02:49 UTC
+++ chrome/browser/task_manager/task_manager_observer.h
@@ -40,11 +40,11 @@ enum RefreshType {
   // or backgrounded.
   REFRESH_TYPE_PRIORITY          = 1 << 11,
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // For observers interested in getting the number of open file descriptors of
   // processes.
   REFRESH_TYPE_FD_COUNT          = 1 << 12,
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   REFRESH_TYPE_MEMORY            = REFRESH_TYPE_PHYSICAL_MEMORY |
                                    REFRESH_TYPE_MEMORY_DETAILS,
