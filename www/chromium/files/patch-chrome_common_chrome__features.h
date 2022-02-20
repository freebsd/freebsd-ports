--- chrome/common/chrome_features.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/common/chrome_features.h
@@ -92,7 +92,7 @@ extern const base::Feature kArcPiGhostWindow;
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kAsyncDns;
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kAutofillAddressSurvey;
 COMPONENT_EXPORT(CHROME_FEATURES)
@@ -101,7 +101,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kAutofillPasswordSurvey;
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
 #endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
@@ -118,7 +118,7 @@ extern const base::Feature kBrowserAppInstanceTracking
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kChangePictureVideoMode;
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kChromeAppsDeprecation;
 #endif
@@ -183,7 +183,7 @@ extern const base::Feature kPreinstalledWebAppInstalla
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kDesktopPWAsAppIconShortcutsMenuUI;
 #endif
@@ -418,7 +418,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kIncognitoNtpRevamp;
 
 #if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kIncognitoBrandConsistencyForDesktop;
 
@@ -445,7 +445,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kKernelnextVMs;
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kLinuxLowMemoryMonitor;
 COMPONENT_EXPORT(CHROME_FEATURES)
