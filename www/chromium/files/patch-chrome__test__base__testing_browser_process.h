--- ./chrome/test/base/testing_browser_process.h.orig	2014-08-12 21:02:10.000000000 +0200
+++ ./chrome/test/base/testing_browser_process.h	2014-08-13 09:56:57.000000000 +0200
@@ -100,8 +100,8 @@
   virtual DownloadStatusUpdater* download_status_updater() OVERRIDE;
   virtual DownloadRequestLimiter* download_request_limiter() OVERRIDE;
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
-  virtual void StartAutoupdateTimer() OVERRIDE {}
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
+  virtual void StartAutoupdateTimer() /*OVERRIDE*/ {}
 #endif
 
   virtual ChromeNetLog* net_log() OVERRIDE;
