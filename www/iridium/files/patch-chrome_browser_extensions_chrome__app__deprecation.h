--- chrome/browser/extensions/chrome_app_deprecation.h.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/extensions/chrome_app_deprecation.h
@@ -24,7 +24,7 @@ namespace testing {
 extern bool g_enable_chrome_apps_for_testing;
 }  // namespace testing
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns whether the extension with `extension_id` is an unsupported
 // deprecated app (hosted app, legacy packaged app, or platform app) on
 // Windows/Mac/Linux.
