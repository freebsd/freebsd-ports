--- chrome/common/chrome_features.h.orig	2017-09-07 15:16:51.725565000 +0200
+++ chrome/common/chrome_features.h	2017-09-07 15:17:47.995642000 +0200
@@ -43,9 +43,9 @@
 extern const base::Feature kAutomaticTabDiscarding;
 #endif  // defined(OS_WIN) || defined(OS_MACOSX)
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const base::Feature kBackgroundModeAllowRestart;
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 extern const base::Feature kBlockPromptsIfDismissedOften;
 extern const base::Feature kBlockPromptsIfIgnoredOften;
