--- chrome/browser/ui/browser_window.h.orig	2019-07-24 18:58:12 UTC
+++ chrome/browser/ui/browser_window.h
@@ -448,7 +448,7 @@ class BrowserWindow : public ui::BaseWindow {
       bool is_source_keyboard) = 0;
 
 #if defined(OS_CHROMEOS) || defined(OS_MACOSX) || defined(OS_WIN) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
   virtual void ShowHatsBubbleFromAppMenuButton() = 0;
 #endif
 
