--- chrome/browser/task_manager/task_manager_observer.h.orig	2025-03-05 08:14:56 UTC
+++ chrome/browser/task_manager/task_manager_observer.h
@@ -46,7 +46,7 @@ enum RefreshType {
   // or backgrounded.
   REFRESH_TYPE_PRIORITY = 1 << 13,
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // For observers interested in getting the number of open file descriptors of
   // processes.
   REFRESH_TYPE_FD_COUNT = 1 << 14,
