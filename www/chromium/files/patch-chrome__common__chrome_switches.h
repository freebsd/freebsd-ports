--- ./chrome/common/chrome_switches.h.orig	2014-04-24 22:34:45.000000000 +0200
+++ ./chrome/common/chrome_switches.h	2014-04-24 23:23:43.000000000 +0200
@@ -440,7 +440,7 @@
 extern const char kPasswordStore[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 extern const char kEnableSpeechDispatcher[];
 extern const char kMigrateDataDirForSxS[];
 #endif
