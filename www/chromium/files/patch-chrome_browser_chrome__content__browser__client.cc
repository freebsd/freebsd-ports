--- chrome/browser/chrome_content_browser_client.cc.orig	2025-09-06 10:01:20 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -467,7 +467,7 @@
 #include "components/user_manager/user_manager.h"
 #include "services/service_manager/public/mojom/interface_provider_spec.mojom.h"
 #include "storage/browser/file_system/external_mount_points.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #elif BUILDFLAG(IS_ANDROID)
@@ -565,7 +565,7 @@
 #include "services/network/public/mojom/permissions_policy/permissions_policy_feature.mojom.h"
 #endif  //  !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crash_switches.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -574,7 +574,7 @@
 #include "components/crash/content/browser/crash_handler_host_linux.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.h"
 #endif
 
@@ -582,7 +582,7 @@
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/chrome_browser_main_extra_parts_linux.h"
 #elif BUILDFLAG(IS_OZONE)
 #include "chrome/browser/chrome_browser_main_extra_parts_ozone.h"
@@ -1406,7 +1406,7 @@ void ChromeContentBrowserClient::RegisterLocalStatePre
   registry->RegisterBooleanPref(prefs::kDataURLWhitespacePreservationEnabled,
                                 true);
   registry->RegisterBooleanPref(prefs::kEnableUnsafeSwiftShader, false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kOutOfProcessSystemDnsResolutionEnabled,
                                 true);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
@@ -1628,7 +1628,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
 #elif BUILDFLAG(IS_CHROMEOS)
   main_parts = std::make_unique<ash::ChromeBrowserMainPartsAsh>(
       is_integration_test, &startup_data_);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   main_parts = std::make_unique<ChromeBrowserMainPartsLinux>(
       is_integration_test, &startup_data_);
 #elif BUILDFLAG(IS_ANDROID)
@@ -1659,7 +1659,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
   // Construct additional browser parts. Stages are called in the order in
   // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(
       std::make_unique<ChromeBrowserMainExtraPartsViewsLinux>());
 #else
@@ -1676,7 +1676,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsAsh>());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsLinux>());
 #elif BUILDFLAG(IS_OZONE)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsOzone>());
@@ -1695,7 +1695,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
 
   chrome::AddMetricsExtraParts(main_parts.get());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(
       std::make_unique<
           enterprise_util::ChromeBrowserMainExtraPartsEnterprise>());
@@ -2703,7 +2703,9 @@ void MaybeAppendBlinkSettingsSwitchForFieldTrial(
 void ChromeContentBrowserClient::AppendExtraCommandLineSwitches(
     base::CommandLine* command_line,
     int child_process_id) {
+#ifdef notyet
   crash_keys::AppendStringAnnotationsCommandLineSwitch(command_line);
+#endif
 #if BUILDFLAG(IS_MAC)
   std::unique_ptr<metrics::ClientInfo> client_info =
       GoogleUpdateSettings::LoadMetricsClientInfo();
@@ -2712,7 +2714,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
                                     client_info->client_id);
   }
 #elif BUILDFLAG(IS_POSIX)
-#if !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
   pid_t pid;
   if (crash_reporter::GetHandlerSocket(nullptr, &pid)) {
     command_line->AppendSwitchASCII(
@@ -3044,7 +3046,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   // Opt into a hardened stack canary mitigation if it hasn't already been
   // force-disabled.
   if (!browser_command_line.HasSwitch(switches::kChangeStackGuardOnFork)) {
@@ -4109,7 +4111,7 @@ bool UpdatePreferredColorScheme(WebPreferences* web_pr
   return old_preferred_color_scheme != web_prefs->preferred_color_scheme;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Sets the `root_scrollbar_theme_color` web pref if the user has enabled a
 // custom colored frame for the UI.
 void UpdateRootScrollbarThemeColor(Profile* profile,
@@ -4752,7 +4754,7 @@ void ChromeContentBrowserClient::OverrideWebPreference
 
   UpdatePreferredColorScheme(web_prefs, main_frame_site.GetSiteURL(),
                              web_contents, GetWebTheme());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   UpdateRootScrollbarThemeColor(profile, web_contents, web_prefs);
 #endif  //  BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 
@@ -5030,7 +5032,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -7174,7 +7176,7 @@ bool ChromeContentBrowserClient::ShouldSandboxNetworkS
 bool ChromeContentBrowserClient::ShouldRunOutOfProcessSystemDnsResolution() {
 // This enterprise policy is supported on Android, but the feature will not be
 // launched there.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // This is possibly called before `g_browser_process` is initialized.
   PrefService* local_state;
   if (g_browser_process) {
