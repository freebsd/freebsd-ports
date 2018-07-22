--- chrome/common/chrome_features.h.orig	2018-06-13 00:10:09.000000000 +0200
+++ chrome/common/chrome_features.h	2018-07-20 16:34:38.434106000 +0200
@@ -52,9 +52,9 @@
 extern const base::Feature kAutomaticTabDiscarding;
 #endif  // defined(OS_WIN) || defined(OS_MACOSX)
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const base::Feature kBackgroundModeAllowRestart;
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 extern const base::Feature kBlockPromptsIfDismissedOften;
 extern const base::Feature kBlockPromptsIfIgnoredOften;
@@ -76,7 +76,7 @@
 extern const base::Feature kTabStripKeyboardFocus;
 #endif  // defined(OS_MACOSX)
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
 extern const base::Feature kCertDualVerificationTrialFeature;
 #endif
 
