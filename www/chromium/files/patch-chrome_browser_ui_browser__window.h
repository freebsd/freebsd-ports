--- chrome/browser/ui/browser_window.h.orig	2019-06-04 18:55:18 UTC
+++ chrome/browser/ui/browser_window.h
@@ -435,7 +435,7 @@ class BrowserWindow : public ui::BaseWindow {
       bool is_source_keyboard) = 0;
 
 #if defined(OS_CHROMEOS) || defined(OS_MACOSX) || defined(OS_WIN) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
   virtual void ShowHatsBubbleFromAppMenuButton() = 0;
 #endif
 
