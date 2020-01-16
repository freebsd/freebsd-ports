--- chrome/browser/chrome_content_browser_client.cc.orig	2019-12-16 21:51:23 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -388,7 +388,7 @@
 #include "components/user_manager/user.h"
 #include "components/user_manager/user_manager.h"
 #include "services/service_manager/public/mojom/interface_provider_spec.mojom.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_ANDROID)
 #include "base/android/application_status_listener.h"
@@ -442,7 +442,7 @@
 #endif  //  !defined(OS_ANDROID)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_navigation_throttle.h"
 #include "services/service_manager/sandbox/features.h"
 #endif
@@ -475,7 +475,7 @@
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #if defined(USE_X11)
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux_x11.h"
 #else
@@ -1193,7 +1193,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(
 #elif defined(OS_CHROMEOS)
   main_parts = std::make_unique<chromeos::ChromeBrowserMainPartsChromeos>(
       parameters, startup_data_);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   main_parts =
       std::make_unique<ChromeBrowserMainPartsLinux>(parameters, startup_data_);
 #elif defined(OS_ANDROID)
@@ -1219,7 +1219,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(
     // Construct additional browser parts. Stages are called in the order in
     // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #if defined(USE_X11)
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViewsLinuxX11());
 #else
@@ -1955,7 +1955,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
     command_line->AppendSwitchASCII(switches::kMetricsClientID,
                                     client_info->client_id);
   }
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) && !defined(OS_BSD)
 #if defined(OS_ANDROID)
   bool enable_crash_reporter = true;
 #else
@@ -2212,7 +2212,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
   StackSamplingConfiguration::Get()->AppendCommandLineSwitchForChildProcess(
       process_type, command_line);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Processes may only query perf_event_open with the BPF sandbox disabled.
   if (browser_command_line.HasSwitch(switches::kEnableThreadInstructionCount) &&
       command_line->HasSwitch(service_manager::switches::kNoSandbox)) {
@@ -3526,7 +3526,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -3666,7 +3666,7 @@ void ChromeContentBrowserClient::BindCredentialManager
 }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 bool ShouldEnableAudioSandbox(const policy::PolicyMap& policies) {
   const base::Value* audio_sandbox_enabled_policy_value =
       policies.GetValue(policy::key::kAudioSandboxEnabled);
@@ -3684,7 +3684,7 @@ bool ShouldEnableAudioSandbox(const policy::PolicyMap&
 
 void ChromeContentBrowserClient::WillStartServiceManager() {
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (startup_data_) {
     auto* chrome_feature_list_creator =
         startup_data_->chrome_feature_list_creator();
@@ -3977,7 +3977,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
   }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   MaybeAddThrottle(&throttles,
                    browser_switcher::BrowserSwitcherNavigationThrottle::
                        MaybeCreateThrottleFor(handle));
