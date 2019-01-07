--- chrome/browser/ui/browser_window.h.orig	2018-12-12 22:56:03.000000000 +0100
+++ chrome/browser/ui/browser_window.h	2018-12-16 14:18:41.738945000 +0100
@@ -405,7 +405,7 @@
       bool is_source_keyboard) = 0;
 
 #if defined(OS_CHROMEOS) || defined(OS_MACOSX) || defined(OS_WIN) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
   virtual void ShowHatsBubbleFromAppMenuButton() = 0;
 #endif
 
