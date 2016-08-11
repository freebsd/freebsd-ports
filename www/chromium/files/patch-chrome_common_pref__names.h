--- chrome/common/pref_names.h.orig	2016-05-25 15:00:58.000000000 -0400
+++ chrome/common/pref_names.h	2016-05-27 10:03:13.560677000 -0400
@@ -307,7 +307,7 @@
 extern const char kDeleteTimePeriod[];
 extern const char kLastClearBrowsingDataTime[];
 extern const char kClearBrowsingDataHistoryNoticeShownTimes[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
@@ -477,7 +477,7 @@
 extern const char kDownloadDefaultDirectory[];
 extern const char kDownloadExtensionsToOpen[];
 extern const char kDownloadDirUpgraded[];
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
 
