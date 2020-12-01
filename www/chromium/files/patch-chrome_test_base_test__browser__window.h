--- chrome/test/base/test_browser_window.h.orig	2020-11-13 06:36:38 UTC
+++ chrome/test/base/test_browser_window.h
@@ -179,7 +179,7 @@ class TestBrowserWindow : public BrowserWindow {
       bool is_source_keyboard) override {}
 
 #if defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_WIN) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
   void ShowHatsBubble(const std::string& site_id) override {}
 #endif
 
