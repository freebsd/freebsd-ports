--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -134,7 +134,7 @@
 #include "chrome/credential_provider/common/gcp_strings.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/headless/headless_mode_util.h"
 #include "chrome/browser/ui/startup/web_app_info_recorder_utils.h"
 #include "components/headless/policy/headless_mode_policy.h"
@@ -980,7 +980,7 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
   TRACE_EVENT0("startup", "StartupBrowserCreator::ProcessCmdLineImpl");
   ComputeAndRecordLaunchMode(command_line);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (headless::IsHeadlessMode() &&
       headless::HeadlessModePolicy::IsHeadlessModeDisabled(
           g_browser_process->local_state())) {
@@ -1083,7 +1083,7 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
     silent_launch = true;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Writes open and installed web apps to the specified file without
   // launching a new browser window or tab.
   if (base::FeatureList::IsEnabled(features::kListWebAppsSwitch) &&
@@ -1300,7 +1300,7 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
     CHECK_EQ(profile_info.mode, StartupProfileMode::kBrowserWindow)
         << "Failed launch with app: couldn't pick a profile";
     std::string app_id = command_line.GetSwitchValueASCII(switches::kAppId);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // If Chrome Apps are deprecated and |app_id| is a Chrome App, display the
     // deprecation UI instead of launching the app.
     if (apps::OpenDeprecatedApplicationPrompt(privacy_safe_profile, app_id)) {
