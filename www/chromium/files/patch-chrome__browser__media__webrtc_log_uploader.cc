--- chrome/browser/media/webrtc_log_uploader.cc.orig	2014-10-10 08:54:10 UTC
+++ chrome/browser/media/webrtc_log_uploader.cc
@@ -233,6 +233,8 @@
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
