--- chrome/browser/web_applications/extensions/extension_status_utils.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/web_applications/extensions/extension_status_utils.cc
@@ -94,7 +94,7 @@ bool IsExternalExtensionUninstalled(content::BrowserCo
   return prefs && prefs->IsExternalExtensionUninstalled(extension_id);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsExtensionUnsupportedDeprecatedApp(content::BrowserContext* context,
                                          const std::string& extension_id) {
   if (testing::g_enable_chrome_apps_for_testing) {
