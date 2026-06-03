--- chrome/browser/web_applications/extensions/extension_status_utils.cc.orig	2026-04-15 11:25:12 UTC
+++ chrome/browser/web_applications/extensions/extension_status_utils.cc
@@ -93,7 +93,7 @@ bool IsExternalExtensionUninstalled(content::BrowserCo
   return prefs && prefs->IsExternalExtensionUninstalled(extension_id);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsExtensionUnsupportedDeprecatedApp(content::BrowserContext* context,
                                          const std::string& extension_id) {
   if (testing::g_enable_chrome_apps_for_testing) {
