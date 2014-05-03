--- ./chrome/browser/media/webrtc_log_uploader.cc.orig	2014-04-24 22:35:11.000000000 +0200
+++ ./chrome/browser/media/webrtc_log_uploader.cc	2014-04-24 23:23:42.000000000 +0200
@@ -155,6 +155,8 @@
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
