--- ./chrome/browser/media/webrtc_log_uploader.cc.orig	2014-08-12 21:01:33.000000000 +0200
+++ ./chrome/browser/media/webrtc_log_uploader.cc	2014-08-13 09:56:56.000000000 +0200
@@ -196,6 +196,8 @@
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
