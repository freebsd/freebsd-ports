--- chrome/common/chrome_features.h.orig	2022-07-22 17:30:31 UTC
+++ chrome/common/chrome_features.h
@@ -89,7 +89,7 @@ extern const base::Feature kArcPiGhostWindow;
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kAsyncDns;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kAutofillAddressSurvey;
 COMPONENT_EXPORT(CHROME_FEATURES)
@@ -98,7 +98,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kAutofillPasswordSurvey;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -223,7 +223,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kDesktopPWAsWebBundles;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kDesktopPWAsWebAppSettingsPage;
 COMPONENT_EXPORT(CHROME_FEATURES)
@@ -437,7 +437,7 @@ extern const base::Feature kUpdateHistoryEntryPointsIn
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kIPHInWebUIDemo;
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kLinuxLowMemoryMonitor;
 COMPONENT_EXPORT(CHROME_FEATURES)
@@ -446,7 +446,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::FeatureParam<int> kLinuxLowMemoryMonitorCriticalLevel;
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kListWebAppsSwitch;
 #endif
