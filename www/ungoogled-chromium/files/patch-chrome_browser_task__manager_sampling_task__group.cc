--- chrome/browser/task_manager/sampling/task_group.cc.orig	2025-10-21 16:57:35 UTC
+++ chrome/browser/task_manager/sampling/task_group.cc
@@ -33,7 +33,7 @@ const int kBackgroundRefreshTypesMask =
 #if BUILDFLAG(IS_WIN)
     REFRESH_TYPE_START_TIME | REFRESH_TYPE_CPU_TIME |
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     REFRESH_TYPE_FD_COUNT |
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
     REFRESH_TYPE_PRIORITY;
@@ -93,7 +93,7 @@ TaskGroup::TaskGroup(
                             weak_ptr_factory_.GetWeakPtr()),
         base::BindRepeating(&TaskGroup::OnIdleWakeupsRefreshDone,
                             weak_ptr_factory_.GetWeakPtr()),
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
         base::BindRepeating(&TaskGroup::OnOpenFdCountRefreshDone,
                             weak_ptr_factory_.GetWeakPtr()),
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
@@ -236,7 +236,7 @@ void TaskGroup::RefreshWindowsHandles() {
 #endif  // BUILDFLAG(IS_WIN)
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 void TaskGroup::OnOpenFdCountRefreshDone(int open_fd_count) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
 
