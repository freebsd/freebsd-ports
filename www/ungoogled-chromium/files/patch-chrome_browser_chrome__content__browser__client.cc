--- chrome/browser/chrome_content_browser_client.cc.orig	2023-12-23 12:33:28 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -446,7 +446,7 @@
 #include "storage/browser/file_system/external_mount_points.h"
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #elif BUILDFLAG(IS_ANDROID)
@@ -547,12 +547,12 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "chrome/browser/browser_switcher/browser_switcher_navigation_throttle.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crash_switches.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -563,14 +563,14 @@
 #include "chrome/browser/apps/link_capturing/web_app_link_capturing_delegate.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.h"
 #include "chrome/browser/enterprise/profile_management/profile_management_navigation_throttle.h"
 #include "chrome/browser/ui/webui/app_settings/web_app_settings_navigation_throttle.h"
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/navigation_throttle.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS_ASH)
@@ -586,7 +586,7 @@
 #include "components/lens/lens_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/chrome_browser_main_extra_parts_linux.h"
 #elif BUILDFLAG(IS_OZONE)
 #include "chrome/browser/chrome_browser_main_extra_parts_ozone.h"
@@ -1566,7 +1566,7 @@ void ChromeContentBrowserClient::RegisterLocalStatePre
   registry->RegisterBooleanPref(prefs::kNativeClientForceAllowed, false);
   registry->RegisterBooleanPref(
       policy::policy_prefs::kPPAPISharedImagesForVideoDecoderAllowed, true);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kOutOfProcessSystemDnsResolutionEnabled,
                                 true);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
@@ -1690,7 +1690,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   main_parts = std::make_unique<ChromeBrowserMainPartsLacros>(
       is_integration_test, &startup_data_);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   main_parts = std::make_unique<ChromeBrowserMainPartsLinux>(
       is_integration_test, &startup_data_);
 #elif BUILDFLAG(IS_ANDROID)
@@ -1727,7 +1727,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
       std::make_unique<ChromeBrowserMainExtraPartsViewsLacros>());
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(
       std::make_unique<ChromeBrowserMainExtraPartsViewsLinux>());
 #else
@@ -1748,7 +1748,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsLacros>());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsLinux>());
 #elif BUILDFLAG(IS_OZONE)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsOzone>());
@@ -1767,7 +1767,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
 
   chrome::AddMetricsExtraParts(main_parts.get());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(
       std::make_unique<
           chrome::enterprise_util::ChromeBrowserMainExtraPartsEnterprise>());
@@ -2601,6 +2601,8 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
 #if(0)
 #if BUILDFLAG(IS_ANDROID)
   bool enable_crash_reporter = true;
+#elif BUILDFLAG(IS_BSD)
+  bool enable_crash_reporter = false;
 #elif BUILDFLAG(IS_CHROMEOS)
   bool enable_crash_reporter = false;
   if (crash_reporter::IsCrashpadEnabled()) {
@@ -2966,7 +2968,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
   ThreadProfilerConfiguration::Get()->AppendCommandLineSwitchForChildProcess(
       command_line);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   // Opt into a hardened stack canary mitigation if it hasn't already been
   // force-disabled.
   if (!browser_command_line.HasSwitch(switches::kChangeStackGuardOnFork)) {
@@ -4637,7 +4639,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -5192,7 +5194,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
         &throttles);
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   MaybeAddThrottle(
       WebAppSettingsNavigationThrottle::MaybeCreateThrottleFor(handle),
       &throttles);
@@ -5202,7 +5204,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   MaybeAddThrottle(enterprise_connectors::DeviceTrustNavigationThrottle::
                        MaybeCreateThrottleFor(handle),
                    &throttles);
@@ -5233,7 +5235,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MaybeAddThrottle(browser_switcher::BrowserSwitcherNavigationThrottle::
                        MaybeCreateThrottleFor(handle),
                    &throttles);
@@ -7101,7 +7103,7 @@ bool ChromeContentBrowserClient::ShouldSandboxNetworkS
 bool ChromeContentBrowserClient::ShouldRunOutOfProcessSystemDnsResolution() {
 // This enterprise policy is supported on Android, but the feature will not be
 // launched there.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // This is possibly called before `g_browser_process` is initialized.
   PrefService* local_state;
   if (g_browser_process) {
