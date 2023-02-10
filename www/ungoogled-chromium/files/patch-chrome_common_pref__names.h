--- chrome/common/pref_names.h.orig	2023-01-13 08:56:02 UTC
+++ chrome/common/pref_names.h
@@ -398,7 +398,7 @@ extern const char kUseAshProxy[];
 #endif  //  BUILDFLAG(IS_CHROMEOS_LACROS)
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // TODO(https://crbug.com/1317782): Remove in M110.
 extern const char kUsesSystemThemeDeprecated[];
 extern const char kSystemTheme[];
@@ -425,7 +425,7 @@ extern const char kShowUpdatePromotionInfoBar[];
 #endif
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 extern const char kUseCustomChromeFrame[];
 #endif
 #if BUILDFLAG(ENABLE_PLUGINS)
@@ -616,7 +616,7 @@ extern const char kDownloadAllowedURLsForOpenByPolicy[
 extern const char kDownloadDirUpgraded[];
 extern const char kDownloadLastCompleteTime[];
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
 #if BUILDFLAG(IS_ANDROID)
@@ -728,7 +728,7 @@ extern const char kWebAppsUninstalledDefaultChromeApps
 extern const char kWebAppsPreferences[];
 extern const char kWebAppsIsolationState[];
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 extern const char kWebAppsUrlHandlerInfo[];
 #endif
@@ -859,7 +859,7 @@ extern const char kGloballyScopeHTTPAuthCacheEnabled[]
 extern const char kAmbientAuthenticationInPrivateModesEnabled[];
 extern const char kBasicAuthOverHttpEnabled[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kAuthNegotiateDelegateByKdcPolicy[];
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
 
@@ -1128,7 +1128,7 @@ extern const char kBlockAutoplayEnabled[];
 #endif
 extern const char kSandboxExternalProtocolBlocked[];
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kAllowSystemNotifications[];
 #endif
 
