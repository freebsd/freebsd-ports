--- src/chrome/browser/chrome_content_browser_client.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/chrome_content_browser_client.cc
@@ -635,7 +635,7 @@
 #include "third_party/cros_system_api/switches/chrome_switches.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crash_switches.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -648,7 +648,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/network_header_injection/http_header_injection_proxying_url_loader_factory.h"
 #include "chrome/browser/enterprise/network_header_injection/http_header_injection_utils.h"
 #include "components/webapps/isolated_web_apps/scheme.h"
@@ -879,7 +879,7 @@ GURL ReplaceURLHostAndPath(const GURL& u
 
 bool IsIsolatedWebAppOrigin(const url::Origin& origin) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return origin.scheme() == webapps::kIsolatedAppScheme;
 #else
   return false;
@@ -892,7 +892,7 @@ bool IsClipboardFocusExemptOrigin(const
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool IsIsolatedWebAppUrl(const GURL& url) {
   return url.SchemeIs(webapps::kIsolatedAppScheme);
 }
@@ -988,7 +988,7 @@ blink::mojom::AutoplayPolicy DetermineWe
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // If a user requests Read Aloud audio playbaback through the "Listen to this
   // page" entry point in the context menu, page distillation and TTS engine
   // readiness may take longer than the user gesture timeout. Thus, we allow
@@ -1599,7 +1599,7 @@ void ChromeContentBrowserClient::Registe
   registry->RegisterBooleanPref(prefs::kDataURLWhitespacePreservationEnabled,
                                 true);
   registry->RegisterBooleanPref(prefs::kEnableUnsafeSwiftShader, false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kOutOfProcessSystemDnsResolutionEnabled,
                                 true);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
@@ -2893,7 +2893,9 @@ void MaybeAppendBlinkSettingsSwitchForFi
 void ChromeContentBrowserClient::AppendExtraCommandLineSwitches(
     base::CommandLine* command_line,
     int child_process_id) {
+#if !BUILDFLAG(IS_BSD)
   crash_keys::AppendStringAnnotationsCommandLineSwitch(command_line);
+#endif
 #if BUILDFLAG(IS_MAC)
   std::unique_ptr<metrics::ClientInfo> client_info =
       GoogleUpdateSettings::LoadMetricsClientInfo();
@@ -2902,7 +2904,7 @@ void ChromeContentBrowserClient::AppendE
                                     client_info->client_id);
   }
 #elif BUILDFLAG(IS_POSIX)
-#if !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
   pid_t pid;
   if (crash_reporter::GetHandlerSocket(nullptr, &pid)) {
     command_line->AppendSwitchASCII(
@@ -3263,7 +3265,7 @@ void ChromeContentBrowserClient::AppendE
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Opt into a hardened stack canary mitigation if it hasn't already been
   // force-disabled.
   if (!browser_command_line.HasSwitch(switches::kChangeStackGuardOnFork)) {
@@ -4074,7 +4076,7 @@ GetPreferredColorScheme(const WebPrefere
 
 std::optional<SkColor> GetRootScrollbarThemeColor(WebContents* web_contents) {
   bool root_scrollbar_follows_browser_theme = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   root_scrollbar_follows_browser_theme = base::FeatureList::IsEnabled(
       blink::features::kRootScrollbarFollowsBrowserTheme);
 #endif
@@ -4877,7 +4879,7 @@ void ChromeContentBrowserClient::Overrid
   web_prefs->touch_drag_drop_enabled =
       base::FeatureList::IsEnabled(features::kTouchDragAndDrop);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   web_prefs->touch_dragend_context_menu =
       base::FeatureList::IsEnabled(features::kTouchDragAndDrop);
 #endif
@@ -5133,7 +5135,7 @@ void ChromeContentBrowserClient::GetAddi
   additional_allowed_schemes->push_back(content::kChromeUIScheme);
   additional_allowed_schemes->push_back(content::kChromeUIUntrustedScheme);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   additional_allowed_schemes->push_back(webapps::kIsolatedAppScheme);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -5187,7 +5189,7 @@ void ChromeContentBrowserClient::GetAddi
   }
 }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -6190,7 +6192,7 @@ ChromeContentBrowserClient::CreateNonNet
   }
 #endif  // BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (scheme == webapps::kIsolatedAppScheme) {
     if (content::AreIsolatedWebAppsEnabled(browser_context) &&
         !browser_context->ShutdownStarted()) {
@@ -6262,7 +6264,7 @@ void ChromeContentBrowserClient::
   DCHECK(factories);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::AreIsolatedWebAppsEnabled(browser_context) &&
       !browser_context->ShutdownStarted()) {
     std::optional<url::Origin> app_origin;
@@ -6308,7 +6310,7 @@ void ChromeContentBrowserClient::
   DCHECK(factories);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::AreIsolatedWebAppsEnabled(browser_context) &&
       !browser_context->ShutdownStarted()) {
     factories->emplace(webapps::kIsolatedAppScheme,
@@ -6587,7 +6589,7 @@ void ChromeContentBrowserClient::
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   {
     auto* rph = content::RenderProcessHost::FromID(render_process_id);
     content::BrowserContext* browser_context = rph->GetBrowserContext();
@@ -6706,7 +6708,7 @@ void ChromeContentBrowserClient::WillCre
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Install the HTTP Header Injection proxying factory.
   enterprise_custom_headers::HttpHeaderInjectionProxyingURLLoaderFactory::
       MaybeProxyRequest(browser_context, factory_builder);
@@ -6752,7 +6754,7 @@ void ChromeContentBrowserClient::WillCre
                         factory_builder, is_for_network_service);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // WARNING: This must be the last wrapper in the chain for
   // TrustedURLLoaderHeaderClient. This ensures that our client is the outermost
   // wrapper of `header_client`, allowing us to apply enterprise headers AFTER
@@ -6859,7 +6861,7 @@ ChromeContentBrowserClient::GetWebSocket
   options.options = network::mojom::kWebSocketOptionNone;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (frame) {
     enterprise_custom_headers::MaybeCreateWebSocketHeaderClient(
         frame->GetBrowserContext(), &options.header_client);
@@ -7267,7 +7269,7 @@ bool ChromeContentBrowserClient::HandleE
   CHECK(content::BrowserThread::CurrentlyOn(content::BrowserThread::UI));
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Handle the google-chrome:// scheme (and chromium://).
   // If the scheme is present, we strip it and navigate to the inner URL.
   // This avoids launching a new browser instance via the OS handler.
@@ -7413,7 +7415,7 @@ bool ChromeContentBrowserClient::HandleW
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
   // Rewrite chrome://settings/addresses to chrome://settings/contactInfo.
   if (url->SchemeIs(content::kChromeUIScheme) &&
@@ -7688,7 +7690,7 @@ bool ChromeContentBrowserClient::ShouldS
 bool ChromeContentBrowserClient::ShouldRunOutOfProcessSystemDnsResolution() {
 // This enterprise policy is supported on Android, but the feature will not be
 // launched there.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // This is possibly called before `g_browser_process` is initialized.
   PrefService* local_state;
   if (g_browser_process) {
@@ -8096,7 +8098,7 @@ void ChromeContentBrowserClient::
     GrantAdditionalRequestPrivilegesToWorkerProcess(int child_id,
                                                     const GURL& script_url) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // IWA Service Workers need to be explicitly granted access to their origin
   // because isolated-app: isn't a web-safe scheme that can be accessed by
   // default.
@@ -8607,7 +8609,7 @@ ChromeContentBrowserClient::GetAlternati
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (navigation_handle.IsInPrimaryMainFrame() &&
       content::AreIsolatedWebAppsEnabled(browser_context) &&
       IsIsolatedWebAppUrl(url)) {
