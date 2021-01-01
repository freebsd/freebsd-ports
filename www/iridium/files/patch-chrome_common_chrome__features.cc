--- chrome/common/chrome_features.cc.orig	2020-03-16 18:40:30 UTC
+++ chrome/common/chrome_features.cc
@@ -86,13 +86,13 @@ const base::Feature kAsyncDns {
 #endif
 };
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
 const base::Feature kBackgroundModeAllowRestart{
     "BackgroundModeAllowRestart", base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Once the user declines a notification permission prompt in a WebContents,
 // automatically dismiss subsequent prompts in the same WebContents, from any
