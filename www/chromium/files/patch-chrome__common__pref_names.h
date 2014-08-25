--- ./chrome/common/pref_names.h.orig	2014-04-30 22:42:23.000000000 +0200
+++ ./chrome/common/pref_names.h	2014-05-04 14:38:46.000000000 +0200
@@ -305,7 +305,7 @@
 extern const char kForceSafeSearch[];
 extern const char kDeleteTimePeriod[];
 extern const char kLastClearBrowsingDataTime[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
