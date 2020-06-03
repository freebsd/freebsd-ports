--- chrome/browser/tracing/crash_service_uploader.cc.orig	2020-05-13 18:39:38 UTC
+++ chrome/browser/tracing/crash_service_uploader.cc
@@ -161,6 +161,8 @@ void TraceCrashServiceUploader::DoCompressOnBackground
   const char product[] = "Chrome_Linux";
 #elif defined(OS_ANDROID)
   const char product[] = "Chrome_Android";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
