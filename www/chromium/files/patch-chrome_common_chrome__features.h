--- chrome/common/chrome_features.h.orig	2018-08-01 00:08:33.000000000 +0200
+++ chrome/common/chrome_features.h	2018-08-05 16:48:04.662112000 +0200
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
 
@@ -204,7 +204,7 @@
 extern const base::Feature kAcknowledgeNtpOverrideOnDeactivate;
 #endif
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
 extern const base::Feature kWarnBeforeQuitting;
 #endif
 
