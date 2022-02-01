--- components/feature_engagement/public/feature_list.h.orig	2021-12-31 00:57:29 UTC
+++ components/feature_engagement/public/feature_list.h
@@ -189,7 +189,7 @@ DEFINE_VARIATION_PARAM(kIPHDiscoverFeedHeaderFeature,
                        "IPH_DiscoverFeedHeaderMenu");
 #endif  // defined(OS_IOS)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 DEFINE_VARIATION_PARAM(kIPHDesktopTabGroupsNewGroupFeature,
                        "IPH_DesktopTabGroupsNewGroup");
@@ -215,7 +215,7 @@ DEFINE_VARIATION_PARAM(kIPHUpdatedConnectionSecurityIn
                        "IPH_UpdatedConnectionSecurityIndicators");
 DEFINE_VARIATION_PARAM(kIPHDesktopSharedHighlightingFeature,
                        "IPH_DesktopSharedHighlighting");
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
 }  // namespace
@@ -311,7 +311,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHReadingListMessagesFeature),
         VARIATION_ENTRY(kIPHBadgedTranslateManualTriggerFeature),
         VARIATION_ENTRY(kIPHDiscoverFeedHeaderFeature),
-#elif defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#elif defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
         VARIATION_ENTRY(kIPHDesktopTabGroupsNewGroupFeature),
         VARIATION_ENTRY(kIPHFocusModeFeature),
@@ -330,7 +330,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHProfileSwitchFeature),
         VARIATION_ENTRY(kIPHUpdatedConnectionSecurityIndicatorsFeature),
         VARIATION_ENTRY(kIPHDesktopSharedHighlightingFeature),
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 };
 
