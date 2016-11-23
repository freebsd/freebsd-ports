--- chrome/browser/safe_browsing/permission_reporter.cc.orig	2016-10-06 04:02:12.000000000 +0300
+++ chrome/browser/safe_browsing/permission_reporter.cc	2016-10-14 06:15:01.051089000 +0300
@@ -190,7 +190,7 @@
 #if defined(OS_ANDROID)
   report.set_platform_type(PermissionReport::ANDROID_PLATFORM);
 #elif defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_CHROMEOS) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
   report.set_platform_type(PermissionReport::DESKTOP_PLATFORM);
 #else
 #error Unsupported platform.
