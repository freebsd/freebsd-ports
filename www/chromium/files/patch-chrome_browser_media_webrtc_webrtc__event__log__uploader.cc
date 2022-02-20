--- chrome/browser/media/webrtc/webrtc_event_log_uploader.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/media/webrtc/webrtc_event_log_uploader.cc
@@ -40,7 +40,7 @@ const char kProduct[] = "Chrome";
 const char kProduct[] = "Chrome_Mac";
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
 const char kProduct[] = "Chrome_ChromeOS";
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 const char kProduct[] = "Chrome_Linux";
 #elif defined(OS_ANDROID)
 const char kProduct[] = "Chrome_Android";
