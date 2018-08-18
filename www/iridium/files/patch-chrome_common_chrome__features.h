--- chrome/common/chrome_features.h.orig	2018-05-09 21:05:40.000000000 +0200
+++ chrome/common/chrome_features.h	2018-08-16 09:26:45.525295000 +0200
@@ -52,7 +52,7 @@
 extern const base::Feature kAutomaticTabDiscarding;
 #endif  // defined(OS_WIN) || defined(OS_MACOSX)
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const base::Feature kBackgroundModeAllowRestart;
 #endif  // defined(OS_WIN) || defined(OS_LINUX)
 
@@ -76,7 +76,7 @@
 extern const base::Feature kTabStripKeyboardFocus;
 #endif  // defined(OS_MACOSX)
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
 extern const base::Feature kCertDualVerificationTrialFeature;
 #endif
 
