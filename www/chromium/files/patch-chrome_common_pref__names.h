--- chrome/common/pref_names.h.orig	2020-09-08 19:14:01 UTC
+++ chrome/common/pref_names.h
@@ -349,7 +349,7 @@ extern const char kHistoryMenuPromoShown[];
 extern const char kForceGoogleSafeSearch[];
 extern const char kForceYouTubeRestrict[];
 extern const char kAllowedDomainsForApps[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
@@ -380,7 +380,7 @@ extern const char kDefaultBrowserSettingEnabled[];
 #if defined(OS_MACOSX)
 extern const char kShowUpdatePromotionInfoBar[];
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUseCustomChromeFrame[];
 #endif
 #if BUILDFLAG(ENABLE_PLUGINS)
@@ -556,7 +556,7 @@ extern const char kDownloadExtensionsToOpen[];
 extern const char kDownloadExtensionsToOpenByPolicy[];
 extern const char kDownloadAllowedURLsForOpenByPolicy[];
 extern const char kDownloadDirUpgraded[];
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
 #if defined(OS_ANDROID)
@@ -776,9 +776,9 @@ extern const char kAllowCrossOriginAuthPrompt[];
 extern const char kGloballyScopeHTTPAuthCacheEnabled[];
 extern const char kAmbientAuthenticationInPrivateModesEnabled[];
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const char kAuthNegotiateDelegateByKdcPolicy[];
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_POSIX)
 extern const char kNtlmV2Enabled[];
@@ -1010,7 +1010,7 @@ extern const char kAutoplayWhitelist[];
 extern const char kBlockAutoplayEnabled[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kAllowNativeNotifications[];
 #endif
 
