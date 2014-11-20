--- chrome/browser/about_flags.cc.orig	2014-10-10 09:15:30 UTC
+++ chrome/browser/about_flags.cc
@@ -2260,7 +2260,7 @@
   return kOsWin;
 #elif defined(OS_CHROMEOS)  // Needs to be before the OS_LINUX check.
   return kOsCrOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kOsLinux;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
