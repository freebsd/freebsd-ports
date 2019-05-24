--- chrome/common/pref_names.h.orig	2019-04-30 22:22:38 UTC
+++ chrome/common/pref_names.h
@@ -301,7 +301,7 @@ extern const char kHistoryMenuPromoShown[];
 extern const char kForceGoogleSafeSearch[];
 extern const char kForceYouTubeRestrict[];
 extern const char kAllowedDomainsForApps[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
@@ -334,7 +334,7 @@ extern const char kDefaultBrowserSettingEnabled[];
 #if defined(OS_MACOSX)
 extern const char kShowUpdatePromotionInfoBar[];
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUseCustomChromeFrame[];
 #endif
 #if BUILDFLAG(ENABLE_PLUGINS)
@@ -490,7 +490,7 @@ extern const char kAppWindowPlacement[];
 extern const char kDownloadDefaultDirectory[];
 extern const char kDownloadExtensionsToOpen[];
 extern const char kDownloadDirUpgraded[];
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
 #if defined(OS_ANDROID)
