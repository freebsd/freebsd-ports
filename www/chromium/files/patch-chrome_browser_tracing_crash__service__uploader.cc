--- chrome/browser/tracing/crash_service_uploader.cc.orig	2016-05-11 19:02:15 UTC
+++ chrome/browser/tracing/crash_service_uploader.cc
@@ -150,6 +150,8 @@ void TraceCrashServiceUploader::DoUpload
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
