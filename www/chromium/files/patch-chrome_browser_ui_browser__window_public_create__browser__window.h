--- chrome/browser/ui/browser_window/public/create_browser_window.h.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/browser_window/public/create_browser_window.h
@@ -181,7 +181,7 @@ struct BrowserWindowCreateParams {
   std::optional<int64_t> display_id;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // When the browser window is shown, the desktop environment is notified
   // using this ID. In response, the desktop will stop playing the "waiting
   // for startup" animation (if any).
