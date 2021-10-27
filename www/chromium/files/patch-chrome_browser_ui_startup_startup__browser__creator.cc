--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2021-09-24 04:26:00 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -131,7 +131,7 @@
 #include "chrome/browser/ui/startup/web_app_protocol_handling_startup_utils.h"
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 #include "chrome/browser/ui/startup/web_app_url_handling_startup_utils.h"
 #endif
 
@@ -470,7 +470,7 @@ bool MaybeLaunchApplication(
   return false;
 }
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 bool MaybeLaunchUrlHandlerWebAppFromCmd(
     const base::CommandLine& command_line,
     const base::FilePath& cur_dir,
@@ -1103,7 +1103,7 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
 
   if (command_line.HasSwitch(switches::kAppId)) {
     std::string app_id = command_line.GetSwitchValueASCII(switches::kAppId);
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     // If Chrome Apps are deprecated and |app_id| is a Chrome App, display the
     // deprecation UI instead of launching the app.
     if (apps::OpenDeprecatedApplicationPrompt(privacy_safe_profile, app_id))
@@ -1175,7 +1175,7 @@ bool StartupBrowserCreator::StartupLaunchAfterProtocol
   }
 
   // Web app URL handling.
-#if defined(OS_WIN) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   if (MaybeLaunchUrlHandlerWebAppFromCmd(command_line, cur_dir, process_startup,
                                          last_used_profile,
                                          last_opened_profiles)) {
