--- chrome/common/chrome_features.h.orig	2022-02-28 16:54:41 UTC
+++ chrome/common/chrome_features.h
@@ -95,7 +95,7 @@ extern const base::Feature kArcPiGhostWindow;
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kAsyncDns;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kAutofillAddressSurvey;
 COMPONENT_EXPORT(CHROME_FEATURES)
@@ -104,7 +104,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kAutofillPasswordSurvey;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -121,7 +121,7 @@ extern const base::Feature kBrowserAppInstanceTracking
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kChangePictureVideoMode;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kChromeAppsDeprecation;
 #endif
@@ -186,7 +186,7 @@ extern const base::Feature kPreinstalledWebAppInstalla
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kDesktopPWAsAppIconShortcutsMenuUI;
 #endif
@@ -410,7 +410,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kImmersiveFullscreen;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kImproveAccessibilityTreeUsingLocalML;
 #endif
@@ -435,7 +435,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kIncognitoNtpRevamp;
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kIncognitoBrandConsistencyForDesktop;
 
@@ -462,7 +462,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kLinkCapturingUiUpdate;
 #endif
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kLinuxLowMemoryMonitor;
 COMPONENT_EXPORT(CHROME_FEATURES)
@@ -471,7 +471,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::FeatureParam<int> kLinuxLowMemoryMonitorCriticalLevel;
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kListWebAppsSwitch;
 #endif
