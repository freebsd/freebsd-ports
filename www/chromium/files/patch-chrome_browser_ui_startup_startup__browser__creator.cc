--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -124,7 +124,7 @@
 #endif  // BUILDFLAG(ENABLE_PRINT_PREVIEW)
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "chrome/browser/ui/startup/web_app_url_handling_startup_utils.h"
 #endif
@@ -403,7 +403,7 @@ bool MaybeLaunchAppShortcutWindow(const base::CommandL
   return false;
 }
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 bool MaybeLaunchUrlHandlerWebAppFromCmd(
     const base::CommandLine& command_line,
     const base::FilePath& cur_dir,
@@ -1038,7 +1038,7 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
 
   if (command_line.HasSwitch(switches::kAppId)) {
     std::string app_id = command_line.GetSwitchValueASCII(switches::kAppId);
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     // If Chrome Apps are deprecated and |app_id| is a Chrome App, display the
     // deprecation UI instead of launching the app.
     if (apps::OpenDeprecatedApplicationPrompt(privacy_safe_profile, app_id))
@@ -1074,7 +1074,7 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
       web_app::startup::MaybeHandleWebAppLaunch(
           command_line, cur_dir, privacy_safe_profile, is_first_run);
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   handled_as_app = handled_as_app ||
                    // Give web apps a chance to handle a URL.
                    MaybeLaunchUrlHandlerWebAppFromCmd(
