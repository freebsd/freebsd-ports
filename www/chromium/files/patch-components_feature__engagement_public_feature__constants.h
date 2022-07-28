--- components/feature_engagement/public/feature_constants.h.orig	2022-07-22 17:30:31 UTC
+++ components/feature_engagement/public/feature_constants.h
@@ -32,7 +32,7 @@ extern const base::Feature kIPHDummyFeature;
 extern const base::Feature kEnableIPH;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 extern const base::Feature kIPHDesktopSharedHighlightingFeature;
 extern const base::Feature kIPHDesktopTabGroupsNewGroupFeature;
 extern const base::Feature kIPHFocusHelpBubbleScreenReaderPromoFeature;
@@ -180,7 +180,7 @@ extern const base::Feature kIPHPasswordSuggestionsFeat
 extern const base::Feature kIPHFollowWhileBrowsingFeature;
 #endif  // BUILDFLAG(IS_IOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
 extern const base::Feature kIPHAutofillVirtualCardSuggestionFeature;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) ||
