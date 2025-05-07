--- chrome/browser/web_applications/extensions/extension_status_utils.cc.orig	2025-05-07 06:48:23 UTC
+++ chrome/browser/web_applications/extensions/extension_status_utils.cc
@@ -26,7 +26,7 @@ namespace {
 
 const char* g_preinstalled_app_for_testing = nullptr;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // TODO(b/268221237): Remove this allow-list.
 const char kDefaultAllowedExtensionIds[] =
     "alhngdkjgnedakdlnamimgfihgkmenbh,"
@@ -105,7 +105,7 @@ bool IsExternalExtensionUninstalled(content::BrowserCo
   return prefs && prefs->IsExternalExtensionUninstalled(extension_id);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsExtensionUnsupportedDeprecatedApp(content::BrowserContext* context,
                                          const std::string& extension_id) {
   if (testing::g_enable_chrome_apps_for_testing) {
