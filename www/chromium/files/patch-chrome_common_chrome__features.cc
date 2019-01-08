--- chrome/common/chrome_features.cc.orig	2018-12-03 21:16:43.000000000 +0100
+++ chrome/common/chrome_features.cc	2018-12-05 16:12:25.391529000 +0100
@@ -91,13 +91,13 @@
                                             base::FEATURE_ENABLED_BY_DEFAULT};
 #endif  // defined(OS_WIN) || defined(OS_MACOSX)
 
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
@@ -152,7 +152,7 @@
     "ThirdPartyModulesBlocking", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
 // Enables the dual certificate verification trial feature.
 // https://crbug.com/649026
 const base::Feature kCertDualVerificationTrialFeature{
@@ -201,7 +201,7 @@
 // Enables or disables windowing related features for desktop PWAs.
 const base::Feature kDesktopPWAWindowing {
   "DesktopPWAWindowing",
-#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
