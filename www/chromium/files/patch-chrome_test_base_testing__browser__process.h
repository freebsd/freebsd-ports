--- chrome/test/base/testing_browser_process.h.orig	2016-05-11 19:02:17 UTC
+++ chrome/test/base/testing_browser_process.h
@@ -104,8 +104,8 @@ class TestingBrowserProcess : public Bro
   DownloadStatusUpdater* download_status_updater() override;
   DownloadRequestLimiter* download_request_limiter() override;
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
-  void StartAutoupdateTimer() override {}
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
+  void StartAutoupdateTimer() /*override*/ {}
 #endif
 
   net_log::ChromeNetLog* net_log() override;
