--- chrome/common/pref_names.h.orig	2021-12-31 00:57:26 UTC
+++ chrome/common/pref_names.h
@@ -371,7 +371,7 @@ extern const char kUseAshProxy[];
 #endif  //  BUILDFLAG(IS_CHROMEOS_LACROS)
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
@@ -400,7 +400,7 @@ extern const char kShowUpdatePromotionInfoBar[];
 #endif
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 extern const char kUseCustomChromeFrame[];
 #endif
 #if BUILDFLAG(ENABLE_PLUGINS)
@@ -582,7 +582,7 @@ extern const char kDownloadExtensionsToOpen[];
 extern const char kDownloadExtensionsToOpenByPolicy[];
 extern const char kDownloadAllowedURLsForOpenByPolicy[];
 extern const char kDownloadDirUpgraded[];
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
@@ -691,7 +691,7 @@ extern const char kWebAppsPreferences[];
 extern const char kWebAppsIsolationState[];
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 extern const char kWebAppsUrlHandlerInfo[];
 #endif
 
@@ -831,9 +831,9 @@ extern const char kGloballyScopeHTTPAuthCacheEnabled[]
 extern const char kAmbientAuthenticationInPrivateModesEnabled[];
 extern const char kBasicAuthOverHttpEnabled[];
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const char kAuthNegotiateDelegateByKdcPolicy[];
-#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_POSIX) || defined(OS_FUCHSIA)
 extern const char kNtlmV2Enabled[];
@@ -1079,7 +1079,7 @@ extern const char kBlockAutoplayEnabled[];
 #endif
 extern const char kSandboxExternalProtocolBlocked[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kAllowNativeNotifications[];
 extern const char kAllowSystemNotifications[];
 #endif
