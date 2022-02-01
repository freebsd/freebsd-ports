--- components/feature_engagement/public/feature_list.cc.orig	2021-12-31 00:57:29 UTC
+++ components/feature_engagement/public/feature_list.cc
@@ -102,7 +102,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHBadgedTranslateManualTriggerFeature,
     &kIPHDiscoverFeedHeaderFeature,
 #endif  // defined(OS_IOS)
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
     &kIPHDesktopTabGroupsNewGroupFeature,
     &kIPHFocusHelpBubbleScreenReaderPromoFeature,
@@ -120,7 +120,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHProfileSwitchFeature,
     &kIPHUpdatedConnectionSecurityIndicatorsFeature,
     &kIPHDesktopSharedHighlightingFeature,
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 };
 }  // namespace
