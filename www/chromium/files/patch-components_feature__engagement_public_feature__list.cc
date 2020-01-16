--- components/feature_engagement/public/feature_list.cc.orig	2019-12-16 21:51:25 UTC
+++ components/feature_engagement/public/feature_list.cc
@@ -54,7 +54,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHBadgedReadingListFeature,
     &kIPHBadgedTranslateManualTriggerFeature,
 #endif  // defined(OS_IOS)
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     &kIPHFocusModeFeature,
     &kIPHGlobalMediaControlsFeature,
@@ -64,7 +64,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHIncognitoWindowFeature,
     &kIPHNewTabFeature,
 #endif  // BUILDFLAG(ENABLE_LEGACY_DESKTOP_IN_PRODUCT_HELP)
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 };
 }  // namespace
