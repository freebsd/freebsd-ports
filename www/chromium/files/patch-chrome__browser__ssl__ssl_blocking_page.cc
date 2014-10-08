--- chrome/browser/ssl/ssl_blocking_page.cc.orig	2014-10-02 17:39:46 UTC
+++ chrome/browser/ssl/ssl_blocking_page.cc
@@ -260,7 +260,7 @@
   // settings. Weird. TODO(palmer): Do something more graceful than ignoring
   // the user's click! crbug.com/394993
   return;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   struct ClockCommand {
     const char* pathname;
     const char* argument;
@@ -310,7 +310,7 @@
 #if !defined(OS_CHROMEOS)
   base::LaunchOptions options;
   options.wait = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   options.allow_new_privs = true;
 #endif
   base::LaunchProcess(command, options, NULL);
