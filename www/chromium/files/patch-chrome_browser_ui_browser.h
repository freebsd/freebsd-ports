--- chrome/browser/ui/browser.h.orig	2022-07-22 17:30:31 UTC
+++ chrome/browser/ui/browser.h
@@ -282,7 +282,7 @@ class Browser : public TabStripModelObserver,
     int32_t restore_id = kDefaultRestoreId;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // When the browser window is shown, the desktop environment is notified
     // using this ID.  In response, the desktop will stop playing the "waiting
     // for startup" animation (if any).
