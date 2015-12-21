--- ./chrome/browser/ssl/bad_clock_blocking_page.cc.orig	2015-12-04 22:09:59.759216000 +0100
+++ ./chrome/browser/ssl/bad_clock_blocking_page.cc	2015-12-04 22:10:08.964486000 +0100
@@ -93,7 +93,7 @@
   // iOS does not have a way to launch the date and time settings.
   NOTREACHED();
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   struct ClockCommand {
     const char* pathname;
     const char* argument;
