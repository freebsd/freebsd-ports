--- chrome/browser/ui/browser_window/internal/create_browser_window_non_android.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/browser_window/internal/create_browser_window_non_android.cc
@@ -46,7 +46,7 @@ BrowserWindowCreateParams BrowserWindowCreateParams::C
 #if BUILDFLAG(IS_CHROMEOS)
   clone.display_id = display_id;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   clone.startup_id = startup_id;
 #endif
 #if BUILDFLAG(IS_OZONE)
