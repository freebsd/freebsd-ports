--- ./chrome/common/pref_names.h.orig	2014-04-24 22:34:45.000000000 +0200
+++ ./chrome/common/pref_names.h	2014-04-24 23:23:43.000000000 +0200
@@ -306,7 +306,7 @@
 extern const char kForceSafeSearch[];
 extern const char kDeleteTimePeriod[];
 extern const char kLastClearBrowsingDataTime[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
