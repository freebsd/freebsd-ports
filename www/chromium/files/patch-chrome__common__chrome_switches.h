--- chrome/common/chrome_switches.h.orig	2014-10-02 19:39:46.000000000 +0200
+++ chrome/common/chrome_switches.h	2014-10-15 11:59:52.000000000 +0200
@@ -309,6 +309,7 @@
 extern const char kSpellingServiceFeedbackIntervalSeconds[];
 extern const char kSSLVersionMax[];
 extern const char kSSLVersionMin[];
+extern const char kSSLVersionFallbackMin[];
 extern const char kStartMaximized[];
 extern const char kSupervisedUserId[];
 extern const char kSupervisedUserSyncToken[];
@@ -362,7 +363,7 @@
 extern const char kPasswordStore[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 extern const char kMigrateDataDirForSxS[];
 #endif
 
