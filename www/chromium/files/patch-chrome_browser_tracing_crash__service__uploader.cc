--- chrome/browser/tracing/crash_service_uploader.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/tracing/crash_service_uploader.cc
@@ -160,6 +160,8 @@ void TraceCrashServiceUploader::DoCompressOnBackground
   const char product[] = "Chrome_Linux";
 #elif defined(OS_ANDROID)
   const char product[] = "Chrome_Android";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
