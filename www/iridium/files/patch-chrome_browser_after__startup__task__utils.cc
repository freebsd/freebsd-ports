--- chrome/browser/after_startup_task_utils.cc.orig	2017-05-02 19:02:47 UTC
+++ chrome/browser/after_startup_task_utils.cc
@@ -93,7 +93,7 @@ void QueueTask(std::unique_ptr<AfterStar
 
 void SetBrowserStartupIsComplete() {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   // CurrentProcessInfo::CreationTime() is not available on all platforms.
   const base::Time process_creation_time =
       base::CurrentProcessInfo::CreationTime();
