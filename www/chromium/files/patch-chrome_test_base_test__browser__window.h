--- chrome/test/base/test_browser_window.h.orig	2021-07-19 18:45:11 UTC
+++ chrome/test/base/test_browser_window.h
@@ -188,7 +188,7 @@ class TestBrowserWindow : public BrowserWindow {
   void MaybeShowProfileSwitchIPH() override {}
 
 #if defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_WIN) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
   void ShowHatsDialog(
       const std::string& site_id,
       base::OnceClosure success_callback,
