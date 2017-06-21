--- chrome/browser/after_startup_task_utils.cc.orig	2017-06-05 19:03:01 UTC
+++ chrome/browser/after_startup_task_utils.cc
@@ -99,7 +99,7 @@ void QueueTask(std::unique_ptr<AfterStartupTask> queue
 
 void SetBrowserStartupIsComplete() {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   // CurrentProcessInfo::CreationTime() is not available on all platforms.
   const base::Time process_creation_time =
       base::CurrentProcessInfo::CreationTime();
