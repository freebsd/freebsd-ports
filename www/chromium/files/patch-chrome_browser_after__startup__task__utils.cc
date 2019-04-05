--- chrome/browser/after_startup_task_utils.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/after_startup_task_utils.cc
@@ -29,7 +29,7 @@
 #include "content/public/browser/web_contents.h"
 #include "content/public/browser/web_contents_observer.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -115,7 +115,7 @@ void QueueTask(std::unique_ptr<AfterStartupTask> queue
 
 void SetBrowserStartupIsComplete() {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   // Process::Current().CreationTime() is not available on all platforms.
   const base::Time process_creation_time =
       base::Process::Current().CreationTime();
@@ -123,7 +123,7 @@ void SetBrowserStartupIsComplete() {
     UMA_HISTOGRAM_LONG_TIMES("Startup.AfterStartupTaskDelayedUntilTime",
                              base::Time::Now() - process_creation_time);
   }
-#endif  // defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   UMA_HISTOGRAM_COUNTS_10000("Startup.AfterStartupTaskCount",
                              g_after_startup_tasks.Get().size());
   g_startup_complete_flag.Get().Set();
@@ -132,7 +132,7 @@ void SetBrowserStartupIsComplete() {
   g_after_startup_tasks.Get().clear();
   g_after_startup_tasks.Get().shrink_to_fit();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Make sure we complete the startup notification sequence, or launchers will
   // get confused by not receiving the expected message from the main process.
   views::LinuxUI* linux_ui = views::LinuxUI::instance();
