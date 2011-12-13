--- chrome/test/base/testing_browser_process.h.orig	2011-11-01 10:43:07.000000000 +0200
+++ chrome/test/base/testing_browser_process.h	2011-11-19 19:35:37.000000000 +0200
@@ -110,7 +110,7 @@
   virtual DownloadRequestLimiter* download_request_limiter() OVERRIDE;
   virtual bool plugin_finder_disabled() const OVERRIDE;
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
   virtual void StartAutoupdateTimer() OVERRIDE {}
 #endif
 
