--- chrome/browser/extensions/chrome_app_deprecation.cc.orig	2026-08-13 07:41:05 UTC
+++ chrome/browser/extensions/chrome_app_deprecation.cc
@@ -16,7 +16,7 @@ namespace testing {
 bool g_enable_chrome_apps_for_testing = false;
 }  // namespace testing
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsExtensionUnsupportedDeprecatedApp(content::BrowserContext* context,
                                          const std::string& extension_id) {
   if (testing::g_enable_chrome_apps_for_testing) {
