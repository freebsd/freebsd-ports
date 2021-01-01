--- chrome/common/chrome_features.h.orig	2020-03-16 18:40:30 UTC
+++ chrome/common/chrome_features.h
@@ -68,10 +68,10 @@ extern const base::Feature kAppServiceShelf;
 
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kAsyncDns;
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBlockRepeatedNotificationPermissionPrompts;
