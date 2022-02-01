--- chrome/test/base/test_browser_window.h.orig	2021-12-31 00:57:26 UTC
+++ chrome/test/base/test_browser_window.h
@@ -199,7 +199,7 @@ class TestBrowserWindow : public BrowserWindow {
   void MaybeShowProfileSwitchIPH() override {}
 
 #if defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_WIN) || \
-    defined(OS_LINUX) || defined(OS_FUCHSIA)
+    defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   void ShowHatsDialog(
       const std::string& site_id,
       base::OnceClosure success_callback,
