--- chrome/browser/after_startup_task_utils.cc.orig	2022-07-22 17:30:31 UTC
+++ chrome/browser/after_startup_task_utils.cc
@@ -105,7 +105,7 @@ void SetBrowserStartupIsComplete() {
 
   g_startup_complete_flag.Get().Set();
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Process::Current().CreationTime() is not available on all platforms.
   const base::Time process_creation_time =
       base::Process::Current().CreationTime();
