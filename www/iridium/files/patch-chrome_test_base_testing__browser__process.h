--- chrome/test/base/testing_browser_process.h.orig	2019-03-11 22:00:54 UTC
+++ chrome/test/base/testing_browser_process.h
@@ -119,8 +119,8 @@ class TestingBrowserProcess : public BrowserProcess {
   DownloadStatusUpdater* download_status_updater() override;
   DownloadRequestLimiter* download_request_limiter() override;
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
-  void StartAutoupdateTimer() override {}
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
+  void StartAutoupdateTimer() /*override*/ {}
 #endif
 
   net_log::ChromeNetLog* net_log() override;
