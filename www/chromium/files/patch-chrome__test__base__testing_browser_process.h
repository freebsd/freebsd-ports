--- chrome/test/base/testing_browser_process.h.orig	2015-01-21 20:28:16 UTC
+++ chrome/test/base/testing_browser_process.h
@@ -103,8 +103,8 @@
   DownloadStatusUpdater* download_status_updater() override;
   DownloadRequestLimiter* download_request_limiter() override;
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
-  void StartAutoupdateTimer() override {}
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
+  void StartAutoupdateTimer() /*override*/ {}
 #endif
 
   ChromeNetLog* net_log() override;
