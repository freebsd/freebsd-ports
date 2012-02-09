--- chrome/browser/about_flags.cc.orig	2012-01-18 11:12:44.000000000 +0200
+++ chrome/browser/about_flags.cc	2012-01-29 14:51:40.000000000 +0200
@@ -674,7 +674,7 @@
   return kOsWin;
 #elif defined(OS_CHROMEOS)  // Needs to be before the OS_LINUX check.
   return kOsCrOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kOsLinux;
 #else
 #error Unknown platform
