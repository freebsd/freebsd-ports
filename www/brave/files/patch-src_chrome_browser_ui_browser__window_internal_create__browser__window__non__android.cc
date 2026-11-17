--- src/chrome/browser/ui/browser_window/internal/create_browser_window_non_android.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/browser_window/internal/create_browser_window_non_android.cc
@@ -46,7 +46,7 @@ BrowserWindowCreateParams BrowserWindowC
 #if BUILDFLAG(IS_CHROMEOS)
   clone.display_id = display_id;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   clone.startup_id = startup_id;
 #endif
 #if BUILDFLAG(IS_OZONE)
