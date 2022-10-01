--- chrome/browser/ui/browser.h.orig	2022-10-01 07:40:07 UTC
+++ chrome/browser/ui/browser.h
@@ -283,7 +283,7 @@ class Browser : public TabStripModelObserver,
     int32_t restore_id = kDefaultRestoreId;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // When the browser window is shown, the desktop environment is notified
     // using this ID.  In response, the desktop will stop playing the "waiting
     // for startup" animation (if any).
