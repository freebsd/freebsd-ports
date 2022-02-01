--- chrome/common/chrome_features.h.orig	2021-12-31 00:57:25 UTC
+++ chrome/common/chrome_features.h
@@ -84,7 +84,7 @@ extern const base::Feature kAppShimNewCloseBehavior;
 
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kAsyncDns;
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kAutofillAddressSurvey;
@@ -94,10 +94,10 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kAutofillPasswordSurvey;
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kBorealis;
@@ -111,7 +111,7 @@ extern const base::Feature kBrowserAppInstanceTracking
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kChangePictureVideoMode;
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kChromeAppsDeprecation;
 #endif
@@ -175,7 +175,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kDefaultPinnedAppsUpdate2021Q2;
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_MAC) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kDesktopPWAsAppIconShortcutsMenuUI;
 #endif
@@ -410,7 +410,7 @@ extern const base::Feature kIncognitoBrandConsistencyF
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kIncognitoNtpRevamp;
 
-#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kIncognitoBrandConsistencyForDesktop;
