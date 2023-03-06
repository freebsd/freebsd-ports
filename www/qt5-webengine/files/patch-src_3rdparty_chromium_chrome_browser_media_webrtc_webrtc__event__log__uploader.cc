--- src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_event_log_uploader.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_event_log_uploader.cc
@@ -42,6 +42,8 @@ const char kProduct[] = "Chrome_Linux";
 const char kProduct[] = "Chrome_ChromeOS";
 #elif defined(OS_LINUX)
 const char kProduct[] = "Chrome_Linux";
+#elif defined(OS_FREEBSD)
+const char kProduct[] = "Chrome_FreeBSD";
 #elif defined(OS_ANDROID)
 const char kProduct[] = "Chrome_Android";
 #else
