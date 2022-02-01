--- chrome/browser/after_startup_task_utils.cc.orig	2021-12-31 00:57:21 UTC
+++ chrome/browser/after_startup_task_utils.cc
@@ -22,7 +22,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -107,7 +107,7 @@ void SetBrowserStartupIsComplete() {
     return;
 
   g_startup_complete_flag.Get().Set();
-#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   // Process::Current().CreationTime() is not available on all platforms.
   const base::Time process_creation_time =
@@ -116,7 +116,7 @@ void SetBrowserStartupIsComplete() {
     UMA_HISTOGRAM_LONG_TIMES("Startup.AfterStartupTaskDelayedUntilTime",
                              base::Time::Now() - process_creation_time);
   }
-#endif  // defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) ||
+#endif  // defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
   UMA_HISTOGRAM_COUNTS_10000("Startup.AfterStartupTaskCount",
                              g_after_startup_tasks.Get().size());
@@ -127,7 +127,7 @@ void SetBrowserStartupIsComplete() {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Make sure we complete the startup notification sequence, or launchers will
   // get confused by not receiving the expected message from the main process.
   views::LinuxUI* linux_ui = views::LinuxUI::instance();
