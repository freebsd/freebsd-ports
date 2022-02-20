--- components/feature_engagement/public/feature_constants.h.orig	2022-02-07 13:39:41 UTC
+++ components/feature_engagement/public/feature_constants.h
@@ -30,7 +30,7 @@ extern const base::Feature kUseClientConfigIPH;
 extern const base::Feature kIPHDummyFeature;
 
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 extern const base::Feature kIPHDesktopSharedHighlightingFeature;
 extern const base::Feature kIPHDesktopTabGroupsNewGroupFeature;
 extern const base::Feature kIPHFocusHelpBubbleScreenReaderPromoFeature;
@@ -160,7 +160,7 @@ extern const base::Feature kIPHBadgedTranslateManualTr
 extern const base::Feature kIPHDiscoverFeedHeaderFeature;
 #endif  // defined(OS_IOS)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
 extern const base::Feature kIPHUpdatedConnectionSecurityIndicatorsFeature;
 #endif
