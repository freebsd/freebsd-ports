--- chrome/browser/media/webrtc_log_uploader.cc.orig	2013-08-17 21:10:06.000000000 +0300
+++ chrome/browser/media/webrtc_log_uploader.cc	2013-08-17 21:10:45.000000000 +0300
@@ -102,6 +102,8 @@
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
   // This file should not be compiled for other platforms.
   COMPILE_ASSERT(false);
