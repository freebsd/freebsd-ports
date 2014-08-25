--- ./chrome/common/pref_names.h.orig	2014-08-20 21:01:56.000000000 +0200
+++ ./chrome/common/pref_names.h	2014-08-22 15:06:25.000000000 +0200
@@ -304,7 +304,7 @@
 extern const char kForceSafeSearch[];
 extern const char kDeleteTimePeriod[];
 extern const char kLastClearBrowsingDataTime[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
