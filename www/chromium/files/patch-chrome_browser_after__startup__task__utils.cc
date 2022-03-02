--- chrome/browser/after_startup_task_utils.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/after_startup_task_utils.cc
@@ -25,7 +25,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -111,7 +111,7 @@ void SetBrowserStartupIsComplete() {
 
   g_startup_complete_flag.Get().Set();
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Process::Current().CreationTime() is not available on all platforms.
   const base::Time process_creation_time =
       base::Process::Current().CreationTime();
@@ -130,7 +130,7 @@ void SetBrowserStartupIsComplete() {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Make sure we complete the startup notification sequence, or launchers will
   // get confused by not receiving the expected message from the main process.
   views::LinuxUI* linux_ui = views::LinuxUI::instance();
