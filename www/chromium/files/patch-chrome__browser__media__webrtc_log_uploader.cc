--- ./chrome/browser/media/webrtc_log_uploader.cc.orig	2014-08-20 21:02:12.000000000 +0200
+++ ./chrome/browser/media/webrtc_log_uploader.cc	2014-08-22 15:06:24.000000000 +0200
@@ -233,6 +233,8 @@
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
