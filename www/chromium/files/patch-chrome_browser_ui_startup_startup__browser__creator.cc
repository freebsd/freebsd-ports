--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2021-07-19 18:45:10 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -126,12 +126,12 @@
 #include "ui/base/ui_base_features.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/startup/web_app_protocol_handling_startup_utils.h"
 #endif
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 #include "chrome/browser/web_applications/components/url_handler_launch_params.h"
 #include "chrome/browser/web_applications/components/url_handler_manager_impl.h"
 #endif
@@ -471,7 +471,7 @@ bool MaybeLaunchApplication(
 }
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 // If |command_line| contains a single URL argument and that URL matches URL
 // handling registration from installed web apps, show app options to user and
 // launch one if accepted.
@@ -999,7 +999,7 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
     }
   }
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
   // Web app Protocol handling.
   auto startup_callback = base::BindOnce(
       [](bool process_startup, const base::CommandLine& command_line,
@@ -1060,7 +1060,7 @@ bool StartupBrowserCreator::StartupLaunchAfterProtocol
 
   // Web app URL handling.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   if (MaybeLaunchUrlHandlerWebApp(command_line, cur_dir,
                                   std::make_unique<LaunchModeRecorder>())) {
     return true;
