--- chrome/common/chrome_features.cc.orig	2026-08-13 16:48:13 UTC
+++ chrome/common/chrome_features.cc
@@ -72,7 +72,7 @@ BASE_FEATURE(kUseKeychainKeyProvider, base::FEATURE_EN
 #endif  // BUILDFLAG(IS_MAC)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables or disables the Autofill survey triggered by opening a prompt to
 // save address info.
 BASE_FEATURE(kAutofillAddressSurvey, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -181,7 +181,7 @@ BASE_FEATURE(kEnableFullscreenToAnyScreenAndroid,
 #endif
 
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Controls whether Chrome Apps are supported. See https://crbug.com/40186761.
 // If the feature is disabled, Chrome Apps continue to work. If enabled, Chrome
 // Apps will not launch and will be marked in the UI as deprecated.
@@ -1326,7 +1326,7 @@ BASE_FEATURE(kIsolatedWebAppManagedGuestSessionInstall
 BASE_FEATURE(kIsolatedWebAppBundleCache, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS)
 BASE_FEATURE(kLinuxLowMemoryMonitor, base::FEATURE_DISABLED_BY_DEFAULT);
 // Values taken from the low-memory-monitor documentation and also apply to the
 // portal API:
@@ -1337,7 +1337,7 @@ constexpr base::FeatureParam<int> kLinuxLowMemoryMonit
     &kLinuxLowMemoryMonitor, "critical_level", 255};
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kListWebAppsSwitch, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
