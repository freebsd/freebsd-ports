--- chrome/browser/chrome_content_browser_client.cc.orig	2025-10-30 15:44:36 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -479,7 +479,7 @@
 #include "components/user_manager/user_manager.h"
 #include "services/service_manager/public/mojom/interface_provider_spec.mojom.h"
 #include "storage/browser/file_system/external_mount_points.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #elif BUILDFLAG(IS_ANDROID)
@@ -577,7 +577,7 @@
 #include "third_party/cros_system_api/switches/chrome_switches.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crash_switches.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -587,12 +587,12 @@
 #include "components/crash/content/browser/crash_handler_host_linux.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.h"
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -601,7 +601,7 @@
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/chrome_browser_main_extra_parts_linux.h"
 #elif BUILDFLAG(IS_OZONE)
 #include "chrome/browser/chrome_browser_main_extra_parts_ozone.h"
@@ -1426,7 +1426,7 @@ void ChromeContentBrowserClient::RegisterLocalStatePre
   registry->RegisterBooleanPref(prefs::kDataURLWhitespacePreservationEnabled,
                                 true);
   registry->RegisterBooleanPref(prefs::kEnableUnsafeSwiftShader, false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kOutOfProcessSystemDnsResolutionEnabled,
                                 true);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
@@ -1649,7 +1649,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
 #elif BUILDFLAG(IS_CHROMEOS)
   main_parts = std::make_unique<ash::ChromeBrowserMainPartsAsh>(
       is_integration_test, &startup_data_);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   main_parts = std::make_unique<ChromeBrowserMainPartsLinux>(
       is_integration_test, &startup_data_);
 #elif BUILDFLAG(IS_ANDROID)
@@ -1680,7 +1680,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
   // Construct additional browser parts. Stages are called in the order in
   // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(
       std::make_unique<ChromeBrowserMainExtraPartsViewsLinux>());
 #else
@@ -1697,7 +1697,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsAsh>());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsLinux>());
 #elif BUILDFLAG(IS_OZONE)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsOzone>());
@@ -1716,7 +1716,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(boo
 
   chrome::AddMetricsExtraParts(main_parts.get());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(
       std::make_unique<
           enterprise_util::ChromeBrowserMainExtraPartsEnterprise>());
@@ -1789,7 +1789,7 @@ ChromeContentBrowserClient::GetStoragePartitionConfigF
 
 #if BUILDFLAG(ENABLE_EXTENSIONS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::SiteIsolationPolicy::ShouldUrlUseApplicationIsolationLevel(
           browser_context, site)) {
     CHECK(url::Origin::Create(site).scheme() == webapps::kIsolatedAppScheme);
@@ -2663,7 +2663,7 @@ bool ChromeContentBrowserClient::ShouldUrlUseApplicati
     const GURL& url) {
 #if BUILDFLAG(ENABLE_EXTENSIONS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
   if (!content::AreIsolatedWebAppsEnabled(browser_context)) {
     return false;
@@ -2781,7 +2781,9 @@ void MaybeAppendBlinkSettingsSwitchForFieldTrial(
 void ChromeContentBrowserClient::AppendExtraCommandLineSwitches(
     base::CommandLine* command_line,
     int child_process_id) {
+#ifdef notyet
   crash_keys::AppendStringAnnotationsCommandLineSwitch(command_line);
+#endif
 #if BUILDFLAG(IS_MAC)
   std::unique_ptr<metrics::ClientInfo> client_info =
       GoogleUpdateSettings::LoadMetricsClientInfo();
@@ -2790,7 +2792,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
                                     client_info->client_id);
   }
 #elif BUILDFLAG(IS_POSIX)
-#if !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
   pid_t pid;
   if (crash_reporter::GetHandlerSocket(nullptr, &pid)) {
     command_line->AppendSwitchASCII(
@@ -3123,7 +3125,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   // Opt into a hardened stack canary mitigation if it hasn't already been
   // force-disabled.
   if (!browser_command_line.HasSwitch(switches::kChangeStackGuardOnFork)) {
@@ -4182,7 +4184,7 @@ GetPreferredColorScheme(const WebPreferences& web_pref
 
 std::optional<SkColor> GetRootScrollbarThemeColor(WebContents* web_contents) {
   bool root_scrollbar_follows_browser_theme = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   root_scrollbar_follows_browser_theme = base::FeatureList::IsEnabled(
       blink::features::kRootScrollbarFollowsBrowserTheme);
 #endif
@@ -5071,7 +5073,7 @@ void ChromeContentBrowserClient::GetAdditionalAllowedS
   additional_allowed_schemes->push_back(content::kChromeUIScheme);
   additional_allowed_schemes->push_back(content::kChromeUIUntrustedScheme);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   additional_allowed_schemes->push_back(webapps::kIsolatedAppScheme);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -5126,7 +5128,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -6002,7 +6004,7 @@ ChromeContentBrowserClient::CreateNonNetworkNavigation
   }
 #endif  // BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (scheme == webapps::kIsolatedAppScheme) {
     if (content::AreIsolatedWebAppsEnabled(browser_context) &&
         !browser_context->ShutdownStarted()) {
@@ -6028,7 +6030,7 @@ void ChromeContentBrowserClient::
   DCHECK(factories);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::AreIsolatedWebAppsEnabled(browser_context) &&
       !browser_context->ShutdownStarted()) {
     factories->emplace(webapps::kIsolatedAppScheme,
@@ -6057,7 +6059,7 @@ void ChromeContentBrowserClient::
   DCHECK(factories);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::AreIsolatedWebAppsEnabled(browser_context) &&
       !browser_context->ShutdownStarted()) {
     factories->emplace(webapps::kIsolatedAppScheme,
@@ -6332,7 +6334,7 @@ void ChromeContentBrowserClient::
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   {
     auto* rph = content::RenderProcessHost::FromID(render_process_id);
     content::BrowserContext* browser_context = rph->GetBrowserContext();
@@ -7302,7 +7304,7 @@ bool ChromeContentBrowserClient::ShouldSandboxNetworkS
 bool ChromeContentBrowserClient::ShouldRunOutOfProcessSystemDnsResolution() {
 // This enterprise policy is supported on Android, but the feature will not be
 // launched there.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // This is possibly called before `g_browser_process` is initialized.
   PrefService* local_state;
   if (g_browser_process) {
@@ -7725,7 +7727,7 @@ void ChromeContentBrowserClient::
     GrantAdditionalRequestPrivilegesToWorkerProcess(int child_id,
                                                     const GURL& script_url) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // IWA Service Workers need to be explicitly granted access to their origin
   // because isolated-app: isn't a web-safe scheme that can be accessed by
   // default.
@@ -8102,7 +8104,7 @@ ChromeContentBrowserClient::GetAlternativeErrorPageOve
     content::BrowserContext* browser_context,
     int32_t error_code) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::AreIsolatedWebAppsEnabled(browser_context) &&
       url.SchemeIs(webapps::kIsolatedAppScheme)) {
     content::mojom::AlternativeErrorPageOverrideInfoPtr
