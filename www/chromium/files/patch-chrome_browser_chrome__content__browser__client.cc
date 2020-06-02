--- chrome/browser/chrome_content_browser_client.cc.orig	2020-05-13 18:40:22 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -396,7 +396,7 @@
 #include "components/user_manager/user.h"
 #include "components/user_manager/user_manager.h"
 #include "services/service_manager/public/mojom/interface_provider_spec.mojom.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_ANDROID)
 #include "base/android/application_status_listener.h"
@@ -450,12 +450,12 @@
 #endif  //  !defined(OS_ANDROID)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_navigation_throttle.h"
 #include "services/service_manager/sandbox/features.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 #include "components/crash/core/app/crash_switches.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -483,7 +483,7 @@
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #endif
 
@@ -789,11 +789,13 @@ breakpad::CrashHandlerHostLinux* CreateCrashHandlerHos
 }
 
 int GetCrashSignalFD(const base::CommandLine& command_line) {
+#if !defined(OS_BSD)
   if (crash_reporter::IsCrashpadEnabled()) {
     int fd;
     pid_t pid;
     return crash_reporter::GetHandlerSocket(&fd, &pid) ? fd : -1;
   }
+#endif
 
   // Extensions have the same process type as renderers.
   if (command_line.HasSwitch(extensions::switches::kExtensionProcess)) {
@@ -1230,7 +1232,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(
 #elif defined(OS_CHROMEOS)
   main_parts = std::make_unique<chromeos::ChromeBrowserMainPartsChromeos>(
       parameters, startup_data_);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   main_parts =
       std::make_unique<ChromeBrowserMainPartsLinux>(parameters, startup_data_);
 #elif defined(OS_ANDROID)
@@ -1256,7 +1258,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(
     // Construct additional browser parts. Stages are called in the order in
     // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViewsLinux());
 #else
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViews());
@@ -1979,7 +1981,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
     command_line->AppendSwitchASCII(switches::kMetricsClientID,
                                     client_info->client_id);
   }
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) && !defined(OS_BSD)
 #if defined(OS_ANDROID)
   bool enable_crash_reporter = true;
 #else
@@ -2256,7 +2258,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
   StackSamplingConfiguration::Get()->AppendCommandLineSwitchForChildProcess(
       process_type, command_line);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Processes may only query perf_event_open with the BPF sandbox disabled.
   if (browser_command_line.HasSwitch(switches::kEnableThreadInstructionCount) &&
       command_line->HasSwitch(service_manager::switches::kNoSandbox)) {
@@ -3546,7 +3548,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -3681,7 +3683,7 @@ void ChromeContentBrowserClient::BindCredentialManager
 }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 bool ShouldEnableAudioSandbox(const policy::PolicyMap& policies) {
   const base::Value* audio_sandbox_enabled_policy_value =
       policies.GetValue(policy::key::kAudioSandboxEnabled);
@@ -3699,7 +3701,7 @@ bool ShouldEnableAudioSandbox(const policy::PolicyMap&
 
 void ChromeContentBrowserClient::WillStartServiceManager() {
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (startup_data_) {
     auto* chrome_feature_list_creator =
         startup_data_->chrome_feature_list_creator();
@@ -3984,7 +3986,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
   }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   MaybeAddThrottle(&throttles,
                    browser_switcher::BrowserSwitcherNavigationThrottle::
                        MaybeCreateThrottleFor(handle));
