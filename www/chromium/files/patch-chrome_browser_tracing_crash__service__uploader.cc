--- chrome/browser/tracing/crash_service_uploader.cc.orig	2017-03-09 20:04:29 UTC
+++ chrome/browser/tracing/crash_service_uploader.cc
@@ -155,6 +155,8 @@ void TraceCrashServiceUploader::DoUpload
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
