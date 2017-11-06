--- chrome/browser/tracing/crash_service_uploader.cc.orig	2017-04-24 14:40:29 UTC
+++ chrome/browser/tracing/crash_service_uploader.cc
@@ -157,6 +157,8 @@ void TraceCrashServiceUploader::DoUpload
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
