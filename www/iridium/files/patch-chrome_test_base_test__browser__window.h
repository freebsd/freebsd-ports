--- chrome/test/base/test_browser_window.h.orig	2020-04-06 07:48:42 UTC
+++ chrome/test/base/test_browser_window.h
@@ -178,7 +178,7 @@ class TestBrowserWindow : public BrowserWindow {
       bool is_source_keyboard) override {}
 
 #if defined(OS_CHROMEOS) || defined(OS_MACOSX) || defined(OS_WIN) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
   void ShowHatsBubble(const std::string& site_id) override {}
 #endif
 
