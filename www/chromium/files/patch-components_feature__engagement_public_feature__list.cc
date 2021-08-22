--- components/feature_engagement/public/feature_list.cc.orig	2021-07-19 18:45:13 UTC
+++ components/feature_engagement/public/feature_list.cc
@@ -89,7 +89,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHBadgedTranslateManualTriggerFeature,
     &kIPHDiscoverFeedHeaderFeature,
 #endif  // defined(OS_IOS)
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     &kIPHDesktopTabGroupsNewGroupFeature,
     &kIPHFocusModeFeature,
@@ -103,7 +103,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHDesktopPwaInstallFeature,
     &kIPHProfileSwitchFeature,
     &kIPHUpdatedConnectionSecurityIndicatorsFeature,
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 };
 }  // namespace
