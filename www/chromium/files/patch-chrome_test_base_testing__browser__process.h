--- chrome/test/base/testing_browser_process.h.orig	2020-11-13 06:36:38 UTC
+++ chrome/test/base/testing_browser_process.h
@@ -124,8 +124,8 @@ class TestingBrowserProcess : public BrowserProcess {
   DownloadRequestLimiter* download_request_limiter() override;
   StartupData* startup_data() override;
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
-  void StartAutoupdateTimer() override {}
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
+  void StartAutoupdateTimer() /*override*/ {}
 #endif
 
   component_updater::ComponentUpdateService* component_updater() override;
