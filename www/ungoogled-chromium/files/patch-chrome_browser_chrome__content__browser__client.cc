--- chrome/browser/chrome_content_browser_client.cc.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -578,7 +578,7 @@
 #include "third_party/cros_system_api/switches/chrome_switches.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crash_switches.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -589,7 +589,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -1415,7 +1415,7 @@ void ChromeContentBrowserClient::RegisterLocalStatePre
   registry->RegisterBooleanPref(prefs::kDataURLWhitespacePreservationEnabled,
                                 true);
   registry->RegisterBooleanPref(prefs::kEnableUnsafeSwiftShader, false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kOutOfProcessSystemDnsResolutionEnabled,
                                 true);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
@@ -1685,7 +1685,7 @@ ChromeContentBrowserClient::GetStoragePartitionConfigF
 
 #if BUILDFLAG(ENABLE_EXTENSIONS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::SiteIsolationPolicy::ShouldUrlUseApplicationIsolationLevel(
           browser_context, site)) {
     CHECK(url::Origin::Create(site).scheme() == webapps::kIsolatedAppScheme);
@@ -2552,7 +2552,7 @@ bool ChromeContentBrowserClient::ShouldUrlUseApplicati
     const GURL& url) {
 #if BUILDFLAG(ENABLE_EXTENSIONS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
   if (!content::AreIsolatedWebAppsEnabled(browser_context)) {
     return false;
@@ -2676,7 +2676,9 @@ void MaybeAppendBlinkSettingsSwitchForFieldTrial(
 void ChromeContentBrowserClient::AppendExtraCommandLineSwitches(
     base::CommandLine* command_line,
     int child_process_id) {
+#if !BUILDFLAG(IS_BSD)
   crash_keys::AppendStringAnnotationsCommandLineSwitch(command_line);
+#endif
 #if BUILDFLAG(IS_MAC)
   std::unique_ptr<metrics::ClientInfo> client_info =
       GoogleUpdateSettings::LoadMetricsClientInfo();
@@ -2685,7 +2687,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
                                     client_info->client_id);
   }
 #elif BUILDFLAG(IS_POSIX)
-#if !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
   pid_t pid;
   if (crash_reporter::GetHandlerSocket(nullptr, &pid)) {
     command_line->AppendSwitchASCII(
@@ -3007,7 +3009,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Opt into a hardened stack canary mitigation if it hasn't already been
   // force-disabled.
   if (!browser_command_line.HasSwitch(switches::kChangeStackGuardOnFork)) {
@@ -4066,7 +4068,7 @@ GetPreferredColorScheme(const WebPreferences& web_pref
 
 std::optional<SkColor> GetRootScrollbarThemeColor(WebContents* web_contents) {
   bool root_scrollbar_follows_browser_theme = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   root_scrollbar_follows_browser_theme = base::FeatureList::IsEnabled(
       blink::features::kRootScrollbarFollowsBrowserTheme);
 #endif
@@ -4998,7 +5000,7 @@ void ChromeContentBrowserClient::GetAdditionalAllowedS
   additional_allowed_schemes->push_back(content::kChromeUIScheme);
   additional_allowed_schemes->push_back(content::kChromeUIUntrustedScheme);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   additional_allowed_schemes->push_back(webapps::kIsolatedAppScheme);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -5053,7 +5055,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -5947,7 +5949,7 @@ ChromeContentBrowserClient::CreateNonNetworkNavigation
   }
 #endif  // BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (scheme == webapps::kIsolatedAppScheme) {
     if (content::AreIsolatedWebAppsEnabled(browser_context) &&
         !browser_context->ShutdownStarted()) {
@@ -5973,7 +5975,7 @@ void ChromeContentBrowserClient::
   DCHECK(factories);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::AreIsolatedWebAppsEnabled(browser_context) &&
       !browser_context->ShutdownStarted()) {
     factories->emplace(webapps::kIsolatedAppScheme,
@@ -6002,7 +6004,7 @@ void ChromeContentBrowserClient::
   DCHECK(factories);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::AreIsolatedWebAppsEnabled(browser_context) &&
       !browser_context->ShutdownStarted()) {
     factories->emplace(webapps::kIsolatedAppScheme,
@@ -6277,7 +6279,7 @@ void ChromeContentBrowserClient::
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   {
     auto* rph = content::RenderProcessHost::FromID(render_process_id);
     content::BrowserContext* browser_context = rph->GetBrowserContext();
@@ -6977,7 +6979,7 @@ bool ChromeContentBrowserClient::HandleWebUI(
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
   // Rewrite chrome://settings/autofill and chrome://settings/enhancedAutofill
   // to chrome://settings/yourSavedInfo.
@@ -7275,7 +7277,7 @@ bool ChromeContentBrowserClient::ShouldSandboxNetworkS
 bool ChromeContentBrowserClient::ShouldRunOutOfProcessSystemDnsResolution() {
 // This enterprise policy is supported on Android, but the feature will not be
 // launched there.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // This is possibly called before `g_browser_process` is initialized.
   PrefService* local_state;
   if (g_browser_process) {
@@ -7714,7 +7716,7 @@ void ChromeContentBrowserClient::
     GrantAdditionalRequestPrivilegesToWorkerProcess(int child_id,
                                                     const GURL& script_url) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // IWA Service Workers need to be explicitly granted access to their origin
   // because isolated-app: isn't a web-safe scheme that can be accessed by
   // default.
@@ -8163,7 +8165,7 @@ ChromeContentBrowserClient::GetAlternativeErrorPageOve
     content::BrowserContext* browser_context,
     int32_t error_code) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::AreIsolatedWebAppsEnabled(browser_context) &&
       url.SchemeIs(webapps::kIsolatedAppScheme)) {
     content::mojom::AlternativeErrorPageOverrideInfoPtr
