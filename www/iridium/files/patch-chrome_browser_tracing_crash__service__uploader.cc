--- chrome/browser/tracing/crash_service_uploader.cc.orig	2018-05-17 22:11:49.335213830 +0200
+++ chrome/browser/tracing/crash_service_uploader.cc	2018-08-16 08:53:50.028885000 +0200
@@ -154,6 +154,8 @@
   const char product[] = "Chrome_Linux";
 #elif defined(OS_ANDROID)
   const char product[] = "Chrome_Android";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
 #else
