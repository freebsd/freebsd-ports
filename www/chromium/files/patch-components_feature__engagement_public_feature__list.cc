--- components/feature_engagement/public/feature_list.cc.orig	2021-09-14 01:51:54 UTC
+++ components/feature_engagement/public/feature_list.cc
@@ -94,7 +94,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHBadgedTranslateManualTriggerFeature,
     &kIPHDiscoverFeedHeaderFeature,
 #endif  // defined(OS_IOS)
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     &kIPHDesktopTabGroupsNewGroupFeature,
     &kIPHFocusModeFeature,
@@ -109,7 +109,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHDesktopPwaInstallFeature,
     &kIPHProfileSwitchFeature,
     &kIPHUpdatedConnectionSecurityIndicatorsFeature,
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 };
 }  // namespace
