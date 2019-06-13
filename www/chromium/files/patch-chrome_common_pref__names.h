--- chrome/common/pref_names.h.orig	2019-06-04 18:55:19 UTC
+++ chrome/common/pref_names.h
@@ -302,7 +302,7 @@ extern const char kHistoryMenuPromoShown[];
 extern const char kForceGoogleSafeSearch[];
 extern const char kForceYouTubeRestrict[];
 extern const char kAllowedDomainsForApps[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
@@ -332,7 +332,7 @@ extern const char kDefaultBrowserSettingEnabled[];
 #if defined(OS_MACOSX)
 extern const char kShowUpdatePromotionInfoBar[];
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUseCustomChromeFrame[];
 #endif
 #if BUILDFLAG(ENABLE_PLUGINS)
@@ -488,7 +488,7 @@ extern const char kAppWindowPlacement[];
 extern const char kDownloadDefaultDirectory[];
 extern const char kDownloadExtensionsToOpen[];
 extern const char kDownloadDirUpgraded[];
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
 #if defined(OS_ANDROID)
@@ -692,9 +692,9 @@ extern const char kGSSAPILibraryName[];
 extern const char kAuthAndroidNegotiateAccountType[];
 extern const char kAllowCrossOriginAuthPrompt[];
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const char kAuthNegotiateDelegateByKdcPolicy[];
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_POSIX)
 extern const char kNtlmV2Enabled[];
