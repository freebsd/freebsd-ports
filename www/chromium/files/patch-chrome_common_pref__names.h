--- chrome/common/pref_names.h.orig	2022-02-07 13:39:41 UTC
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
@@ -583,7 +583,7 @@ extern const char kDownloadExtensionsToOpenByPolicy[];
 extern const char kDownloadAllowedURLsForOpenByPolicy[];
 extern const char kDownloadDirUpgraded[];
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
 #if defined(OS_ANDROID)
@@ -689,7 +689,7 @@ extern const char kWebAppsUninstalledDefaultChromeApps
 extern const char kWebAppsPreferences[];
 extern const char kWebAppsIsolationState[];
 
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 extern const char kWebAppsUrlHandlerInfo[];
 #endif
@@ -830,7 +830,7 @@ extern const char kGloballyScopeHTTPAuthCacheEnabled[]
 extern const char kAmbientAuthenticationInPrivateModesEnabled[];
 extern const char kBasicAuthOverHttpEnabled[];
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const char kAuthNegotiateDelegateByKdcPolicy[];
 #endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
 
@@ -1074,7 +1074,7 @@ extern const char kBlockAutoplayEnabled[];
 #endif
 extern const char kSandboxExternalProtocolBlocked[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kAllowNativeNotifications[];
 extern const char kAllowSystemNotifications[];
 #endif
