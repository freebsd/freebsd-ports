--- chrome/test/base/test_browser_window.h.orig	2021-05-24 22:05:36 UTC
+++ chrome/test/base/test_browser_window.h
@@ -179,7 +179,7 @@ class TestBrowserWindow : public BrowserWindow {
   void MaybeShowProfileSwitchIPH() override {}
 
 #if defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_WIN) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
   void ShowHatsDialog(
       const std::string& site_id,
       base::OnceClosure success_callback,
