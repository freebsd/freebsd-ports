--- chrome/test/base/testing_browser_process.h.orig	2021-01-18 21:28:52 UTC
+++ chrome/test/base/testing_browser_process.h
@@ -125,8 +125,8 @@ class TestingBrowserProcess : public BrowserProcess {
   DownloadRequestLimiter* download_request_limiter() override;
   StartupData* startup_data() override;
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
-  void StartAutoupdateTimer() override {}
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
+  void StartAutoupdateTimer() /*override*/ {}
 #endif
 
   component_updater::ComponentUpdateService* component_updater() override;
