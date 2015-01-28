--- chrome/browser/ssl/ssl_blocking_page.cc.orig	2015-01-21 20:28:15 UTC
+++ chrome/browser/ssl/ssl_blocking_page.cc
@@ -237,7 +237,7 @@
 #elif defined(OS_IOS)
   // iOS does not have a way to launch the date and time settings.
   NOTREACHED();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   struct ClockCommand {
     const char* pathname;
     const char* argument;
@@ -289,7 +289,7 @@
 #if !defined(OS_CHROMEOS) && !defined(OS_ANDROID)
   base::LaunchOptions options;
   options.wait = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   options.allow_new_privs = true;
 #endif
   base::LaunchProcess(command, options, NULL);
