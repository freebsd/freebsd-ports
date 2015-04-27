--- chrome/browser/ssl/ssl_blocking_page.cc.orig	2015-04-18 23:34:15.000000000 +0200
+++ chrome/browser/ssl/ssl_blocking_page.cc	2015-04-18 23:40:51.000000000 +0200
@@ -132,7 +132,7 @@
   // iOS does not have a way to launch the date and time settings.
   NOTREACHED();
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   struct ClockCommand {
     const char* pathname;
     const char* argument;
