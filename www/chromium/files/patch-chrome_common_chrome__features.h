--- chrome/common/chrome_features.h.orig	2019-10-21 19:06:25 UTC
+++ chrome/common/chrome_features.h
@@ -64,10 +64,10 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kAutoFetchOnNetErrorPage;
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBlockPromptsIfDismissedOften;
@@ -86,7 +86,7 @@ extern const base::Feature kBundledConnectionHelpFeatu
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kCaptionSettings;
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kCertDualVerificationTrialFeature;
 #endif
