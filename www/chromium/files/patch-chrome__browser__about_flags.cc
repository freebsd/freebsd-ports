--- ./chrome/browser/about_flags.cc.orig	2014-04-30 22:42:17.000000000 +0200
+++ ./chrome/browser/about_flags.cc	2014-05-04 14:38:46.000000000 +0200
@@ -2153,7 +2153,7 @@
   return kOsWin;
 #elif defined(OS_CHROMEOS)  // Needs to be before the OS_LINUX check.
   return kOsCrOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kOsLinux;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
