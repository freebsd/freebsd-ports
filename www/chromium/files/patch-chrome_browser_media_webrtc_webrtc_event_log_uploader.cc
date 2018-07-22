--- chrome/browser/media/webrtc/webrtc_event_log_uploader.cc.orig	2018-07-19 22:14:21.658215000 +0200
+++ chrome/browser/media/webrtc/webrtc_event_log_uploader.cc	2018-07-19 22:14:37.578585000 +0200
@@ -51,7 +51,7 @@
 const char kProduct[] = "Chrome";
 #elif defined(OS_MACOSX)
 const char kProduct[] = "Chrome_Mac";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 const char kProduct[] = "Chrome_Linux";
 #elif defined(OS_ANDROID)
 const char kProduct[] = "Chrome_Android";
