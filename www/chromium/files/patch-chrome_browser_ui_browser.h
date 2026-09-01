--- chrome/browser/ui/browser.h.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/browser.h
@@ -209,7 +209,7 @@ class Browser : public TabStripModelObserver,
     std::optional<int64_t> display_id;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // When the browser window is shown, the desktop environment is notified
     // using this ID.  In response, the desktop will stop playing the "waiting
     // for startup" animation (if any).
