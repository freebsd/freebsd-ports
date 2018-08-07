--- chrome/common/chrome_features.cc.orig	2018-08-01 00:08:33.000000000 +0200
+++ chrome/common/chrome_features.cc	2018-08-05 16:46:49.046411000 +0200
@@ -85,7 +85,7 @@
                                             base::FEATURE_ENABLED_BY_DEFAULT};
 #endif  // defined(OS_WIN) || defined(OS_MACOSX)
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
@@ -142,7 +142,7 @@
                                        base::FEATURE_ENABLED_BY_DEFAULT};
 #endif
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
 // Enables the dual certificate verification trial feature.
 // https://crbug.com/649026
 const base::Feature kCertDualVerificationTrialFeature{
@@ -367,7 +367,7 @@
     "AcknowledgeNtpOverrideOnDeactivate", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
 const base::Feature kWarnBeforeQuitting{"WarnBeforeQuitting",
                                         base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
