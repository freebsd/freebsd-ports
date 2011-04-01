--- chrome/browser/about_flags.cc.orig	2011-03-20 22:02:04.388735857 +0200
+++ chrome/browser/about_flags.cc	2011-03-20 22:02:04.492737343 +0200
@@ -503,7 +503,7 @@
   return kOsWin;
 #elif defined(OS_CHROMEOS)  // Needs to be before the OS_LINUX check.
   return kOsCrOS;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   return kOsLinux;
 #else
 #error Unknown platform
