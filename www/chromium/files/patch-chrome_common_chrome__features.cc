--- chrome/common/chrome_features.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/common/chrome_features.cc
@@ -84,7 +84,7 @@ BASE_FEATURE(kUseKeychainKeyProvider, base::FEATURE_EN
 #endif  // BUILDFLAG(IS_MAC)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables or disables the Autofill survey triggered by opening a prompt to
 // save address info.
 BASE_FEATURE(kAutofillAddressSurvey, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -232,7 +232,7 @@ BASE_FEATURE(kEnableFullscreenToAnyScreenAndroid,
 // Enables the new reset banner on the settings page.
 BASE_FEATURE(kShowResetProfileBannerV2, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Controls whether Chrome Apps are supported. See https://crbug.com/1221251.
 // If the feature is disabled, Chrome Apps continue to work. If enabled, Chrome
 // Apps will not launch and will be marked in the UI as deprecated.
@@ -800,7 +800,7 @@ BASE_FEATURE(kGlicWarming, base::FEATURE_DISABLED_BY_D
 // Killswitch that controls whether the guest WebContents visibility state is
 // set to hidden when the Glic panel is warming.
 BASE_FEATURE(kGlicGuestContentsVisibilityState,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -1356,7 +1356,7 @@ BASE_FEATURE(kIsolatedWebAppManagedGuestSessionInstall
 BASE_FEATURE(kIsolatedWebAppBundleCache, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS)
 BASE_FEATURE(kLinuxLowMemoryMonitor, base::FEATURE_DISABLED_BY_DEFAULT);
 // Values taken from the low-memory-monitor documentation and also apply to the
 // portal API:
@@ -1367,7 +1367,7 @@ constexpr base::FeatureParam<int> kLinuxLowMemoryMonit
     &kLinuxLowMemoryMonitor, "critical_level", 255};
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kListWebAppsSwitch, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
