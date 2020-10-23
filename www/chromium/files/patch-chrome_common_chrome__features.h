--- chrome/common/chrome_features.h.orig	2020-09-08 19:14:01 UTC
+++ chrome/common/chrome_features.h
@@ -63,10 +63,10 @@ extern const base::Feature kAppServiceAdaptiveIcon;
 
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kAsyncDns;
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(TRIAL_COMPARISON_CERT_VERIFIER_SUPPORTED)
 COMPONENT_EXPORT(CHROME_FEATURES)
