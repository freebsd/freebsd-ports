--- chrome/browser/tracing/crash_service_uploader.cc.orig	2015-04-20 19:15:53.000000000 +0200
+++ chrome/browser/tracing/crash_service_uploader.cc	2015-04-20 19:16:21.000000000 +0200
@@ -127,6 +127,8 @@
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
