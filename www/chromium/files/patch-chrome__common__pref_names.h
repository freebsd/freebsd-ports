--- chrome/common/pref_names.h.orig	2013-08-17 20:35:53.000000000 +0300
+++ chrome/common/pref_names.h	2013-08-17 20:36:25.000000000 +0300
@@ -341,7 +341,7 @@
 extern const char kForceSafeSearch[];
 extern const char kDeleteTimePeriod[];
 extern const char kLastClearBrowsingDataTime[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
