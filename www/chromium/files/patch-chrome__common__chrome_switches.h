--- chrome/common/chrome_switches.h.orig	2013-11-08 07:41:00.000000000 +0100
+++ chrome/common/chrome_switches.h	2013-11-16 01:20:25.000000000 +0100
@@ -435,7 +435,7 @@
 #endif
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 extern const char kMigrateDataDirForSxS[];
 #endif
 
