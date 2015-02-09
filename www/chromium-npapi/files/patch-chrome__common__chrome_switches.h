--- ./chrome/common/chrome_switches.h.orig	2014-04-30 22:42:23.000000000 +0200
+++ ./chrome/common/chrome_switches.h	2014-05-04 14:38:46.000000000 +0200
@@ -406,7 +406,7 @@
 extern const char kPasswordStore[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 extern const char kEnableSpeechDispatcher[];
 extern const char kMigrateDataDirForSxS[];
 #endif
