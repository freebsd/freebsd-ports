--- chrome/browser/tracing/crash_service_uploader.cc.orig	2018-08-01 00:08:32.000000000 +0200
+++ chrome/browser/tracing/crash_service_uploader.cc	2018-08-04 14:37:55.834228000 +0200
@@ -158,6 +158,8 @@
   const char product[] = "Chrome_Linux";
 #elif defined(OS_ANDROID)
   const char product[] = "Chrome_Android";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
