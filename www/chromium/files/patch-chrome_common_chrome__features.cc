--- chrome/common/chrome_features.cc.orig	2025-10-18 06:45:48 UTC
+++ chrome/common/chrome_features.cc
@@ -64,7 +64,7 @@ BASE_FEATURE(UseAdHocSigningForWebAppShims, base::FEAT
 #endif  // BUILDFLAG(IS_MAC)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables or disables the Autofill survey triggered by opening a prompt to
 // save address info.
 BASE_FEATURE(AutofillAddressSurvey, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -76,7 +76,7 @@ BASE_FEATURE(AutofillCardSurvey, base::FEATURE_DISABLE
 BASE_FEATURE(AutofillPasswordSurvey, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
@@ -188,7 +188,7 @@ BASE_FEATURE(DesktopPWAsElidedExtensionsMenu,
 // Enables or disables Desktop PWAs to be auto-started on OS login.
 BASE_FEATURE(DesktopPWAsRunOnOsLogin,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -222,7 +222,7 @@ BASE_FEATURE(EnableFullscreenToAnyScreenAndroid,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Controls whether Chrome Apps are supported. See https://crbug.com/1221251.
 // If the feature is disabled, Chrome Apps continue to work. If enabled, Chrome
 // Apps will not launch and will be marked in the UI as deprecated.
@@ -578,7 +578,7 @@ BASE_FEATURE(GlicDisableWarming, base::FEATURE_ENABLED
 // set to hidden when the Glic panel is warming.
 BASE_FEATURE(kGlicGuestContentsVisibilityState,
              "GlicGuestContentsVisibilityState",
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -1008,7 +1008,7 @@ BASE_FEATURE(KAnonymityServiceOHTTPRequests, base::FEA
 // public keys.
 BASE_FEATURE(KAnonymityServiceStorage, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(LinuxLowMemoryMonitor, base::FEATURE_DISABLED_BY_DEFAULT);
 // Values taken from the low-memory-monitor documentation and also apply to the
 // portal API:
@@ -1019,7 +1019,7 @@ constexpr base::FeatureParam<int> kLinuxLowMemoryMonit
     &kLinuxLowMemoryMonitor, "critical_level", 255};
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(ListWebAppsSwitch, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
