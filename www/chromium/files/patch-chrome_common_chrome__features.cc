--- chrome/common/chrome_features.cc.orig	2019-06-04 18:55:18 UTC
+++ chrome/common/chrome_features.cc
@@ -92,13 +92,13 @@ const base::Feature kAutoFetchOnNetErrorPage{"AutoFetc
                                              base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
 const base::Feature kBackgroundModeAllowRestart{
     "BackgroundModeAllowRestart", base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Enables or disables whether permission prompts are automatically blocked
 // after the user has explicitly dismissed them too many times.
@@ -144,7 +144,7 @@ const base::Feature kThirdPartyModulesBlocking{
     "ThirdPartyModulesBlocking", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
 // Enables the dual certificate verification trial feature.
 // https://crbug.com/649026
 const base::Feature kCertDualVerificationTrialFeature{
@@ -204,7 +204,7 @@ const base::Feature kUsageTimeLimitPolicy{"UsageTimeLi
 // Enables or disables windowing related features for desktop PWAs.
 const base::Feature kDesktopPWAWindowing {
   "DesktopPWAWindowing",
-#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_MACOSX)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
