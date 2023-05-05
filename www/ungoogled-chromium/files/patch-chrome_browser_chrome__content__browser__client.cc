--- chrome/browser/chrome_content_browser_client.cc.orig	2023-05-05 12:12:41 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -419,7 +419,7 @@
 #include "components/user_manager/user_manager.h"
 #include "services/service_manager/public/mojom/interface_provider_spec.mojom.h"
 #include "storage/browser/file_system/external_mount_points.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif BUILDFLAG(IS_ANDROID)
 #include "base/android/application_status_listener.h"
@@ -502,12 +502,12 @@
 
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
@@ -516,14 +516,14 @@
 #include "components/crash/content/browser/crash_handler_host_linux.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.h"
 #include "chrome/browser/enterprise/profile_token_management/profile_token_navigation_throttle.h"
 #include "chrome/browser/ui/webui/app_settings/web_app_settings_navigation_throttle.h"
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/navigation_throttle.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS_ASH)
@@ -552,11 +552,11 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/chrome_browser_main_extra_parts_linux.h"
 #elif BUILDFLAG(IS_OZONE)
 #include "chrome/browser/chrome_browser_main_extra_parts_ozone.h"
@@ -1542,7 +1542,7 @@ void ChromeContentBrowserClient::RegisterLocalStatePre
       policy::policy_prefs::kPPAPISharedImagesSwapChainAllowed, true);
   registry->RegisterBooleanPref(
       policy::policy_prefs::kForceEnablePepperVideoDecoderDevAPI, false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kOutOfProcessSystemDnsResolutionEnabled,
                                 true);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
@@ -1655,7 +1655,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   main_parts = std::make_unique<ChromeBrowserMainPartsLacros>(
       is_integration_test, &startup_data_);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   main_parts = std::make_unique<ChromeBrowserMainPartsLinux>(
       is_integration_test, &startup_data_);
 #elif BUILDFLAG(IS_ANDROID)
@@ -1694,7 +1694,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
       std::make_unique<ChromeBrowserMainExtraPartsViewsLacros>());
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(
       std::make_unique<ChromeBrowserMainExtraPartsViewsLinux>());
 #else
@@ -1715,7 +1715,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsLacros>());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsLinux>());
 #elif BUILDFLAG(IS_OZONE)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsOzone>());
@@ -1734,7 +1734,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
 
   chrome::AddMetricsExtraParts(main_parts.get());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(
       std::make_unique<
           chrome::enterprise_util::ChromeBrowserMainExtraPartsEnterprise>());
@@ -2558,6 +2558,8 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
 #if(0)
 #if BUILDFLAG(IS_ANDROID)
   bool enable_crash_reporter = true;
+#elif BUILDFLAG(IS_BSD)
+  bool enable_crash_reporter = false;
 #elif BUILDFLAG(IS_CHROMEOS)
   bool enable_crash_reporter = false;
   if (crash_reporter::IsCrashpadEnabled()) {
@@ -2927,7 +2929,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
   ThreadProfilerConfiguration::Get()->AppendCommandLineSwitchForChildProcess(
       command_line);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   // Opt into a hardened stack canary mitigation if it hasn't already been
   // force-disabled.
   if (!browser_command_line.HasSwitch(switches::kChangeStackGuardOnFork)) {
@@ -4480,7 +4482,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -4994,7 +4996,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
         &throttles);
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   MaybeAddThrottle(
       WebAppSettingsNavigationThrottle::MaybeCreateThrottleFor(handle),
       &throttles);
@@ -5004,7 +5006,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   MaybeAddThrottle(enterprise_connectors::DeviceTrustNavigationThrottle::
                        MaybeCreateThrottleFor(handle),
                    &throttles);
@@ -5035,7 +5037,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MaybeAddThrottle(browser_switcher::BrowserSwitcherNavigationThrottle::
                        MaybeCreateThrottleFor(handle),
                    &throttles);
@@ -6640,7 +6642,7 @@ bool ChromeContentBrowserClient::ShouldSandboxNetworkS
 }
 
 bool ChromeContentBrowserClient::ShouldRunOutOfProcessSystemDnsResolution() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // This is possibly called before `g_browser_process` is initialized.
   PrefService* local_state;
   if (g_browser_process) {
