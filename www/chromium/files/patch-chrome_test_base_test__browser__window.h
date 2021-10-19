--- chrome/test/base/test_browser_window.h.orig	2021-09-24 04:26:00 UTC
+++ chrome/test/base/test_browser_window.h
@@ -197,7 +197,7 @@ class TestBrowserWindow : public BrowserWindow {
   void MaybeShowProfileSwitchIPH() override {}
 
 #if defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_WIN) || \
-    defined(OS_LINUX) || defined(OS_FUCHSIA)
+    defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   void ShowHatsDialog(
       const std::string& site_id,
       base::OnceClosure success_callback,
