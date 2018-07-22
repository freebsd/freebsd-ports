--- chrome/common/chrome_features.cc.orig	2018-06-13 00:10:09.000000000 +0200
+++ chrome/common/chrome_features.cc	2018-07-20 16:33:58.698475000 +0200
@@ -85,13 +85,13 @@
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
@@ -142,7 +142,7 @@
                                        base::FEATURE_ENABLED_BY_DEFAULT};
 #endif
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
 // Enables the dual certificate verification trial feature.
 // https://crbug.com/649026
 const base::Feature kCertDualVerificationTrialFeature{
