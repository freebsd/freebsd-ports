--- components/feature_engagement/public/feature_list.cc.orig	2022-02-07 13:39:41 UTC
+++ components/feature_engagement/public/feature_list.cc
@@ -111,7 +111,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHDiscoverFeedHeaderFeature,
 #endif  // defined(OS_IOS)
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
     &kIPHDesktopTabGroupsNewGroupFeature,
     &kIPHFocusHelpBubbleScreenReaderPromoFeature,
     &kIPHGMCCastStartStopFeature,
