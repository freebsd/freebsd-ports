--- chrome/common/chrome_features.h.orig	2020-05-13 18:40:25 UTC
+++ chrome/common/chrome_features.h
@@ -59,10 +59,10 @@ extern const base::Feature kAppServiceIntentHandling;
 
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kAsyncDns;
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(TRIAL_COMPARISON_CERT_VERIFIER_SUPPORTED)
 COMPONENT_EXPORT(CHROME_FEATURES)
