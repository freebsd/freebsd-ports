--- chrome/browser/media/webrtc/webrtc_event_log_uploader.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/media/webrtc/webrtc_event_log_uploader.cc
@@ -40,6 +40,8 @@ const char kProduct[] = "Chrome_Mac";
 const char kProduct[] = "Chrome_ChromeOS";
 #elif defined(OS_LINUX)
 const char kProduct[] = "Chrome_Linux";
+#elif defined(OS_FREEBSD)
+const char kProduct[] = "Chrome_FreeBSD";
 #elif defined(OS_ANDROID)
 const char kProduct[] = "Chrome_Android";
 #else
