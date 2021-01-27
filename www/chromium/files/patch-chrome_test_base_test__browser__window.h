--- chrome/test/base/test_browser_window.h.orig	2021-01-18 21:28:52 UTC
+++ chrome/test/base/test_browser_window.h
@@ -176,7 +176,7 @@ class TestBrowserWindow : public BrowserWindow {
       bool is_source_keyboard) override {}
 
 #if defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_WIN) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
   void ShowHatsBubble(const std::string& site_id,
                       base::OnceClosure success_callback,
                       base::OnceClosure failure_callback) override {}
