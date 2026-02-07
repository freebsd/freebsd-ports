--- chrome/browser/ui/web_applications/app_browser_controller.cc.orig	2026-01-14 08:33:23 UTC
+++ chrome/browser/ui/web_applications/app_browser_controller.cc
@@ -524,7 +524,7 @@ std::u16string AppBrowserController::GetLaunchFlashTex
   // web bundle. The flash text is not needed on platforms that already display
   // the app name in the title bar (e.g. Mac, Windows, and Linux).
   if (IsIsolatedWebApp()) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return std::u16string();
 #else   // !(BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX))
     return GetAppShortName();
