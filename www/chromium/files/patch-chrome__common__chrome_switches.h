--- ./chrome/common/chrome_switches.h.orig	2014-08-20 21:01:56.000000000 +0200
+++ ./chrome/common/chrome_switches.h	2014-08-22 15:06:25.000000000 +0200
@@ -378,7 +378,7 @@
 extern const char kPasswordStore[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 extern const char kEnableSpeechDispatcher[];
 extern const char kMigrateDataDirForSxS[];
 #endif
