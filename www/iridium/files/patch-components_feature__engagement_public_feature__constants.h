--- components/feature_engagement/public/feature_constants.h.orig	2023-11-22 14:00:11 UTC
+++ components/feature_engagement/public/feature_constants.h
@@ -24,7 +24,7 @@ BASE_DECLARE_FEATURE(kUseClientConfigIPH);
 BASE_DECLARE_FEATURE(kIPHDummyFeature);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHBatterySaverModeFeature);
 BASE_DECLARE_FEATURE(kIPHCompanionSidePanelFeature);
 BASE_DECLARE_FEATURE(kIPHCompanionSidePanelRegionSearchFeature);
@@ -226,7 +226,7 @@ extern const base::FeatureParam<int>
     kDefaultBrowserEligibilitySlidingWindowParam;
 #endif  // BUILDFLAG(IS_IOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
 BASE_DECLARE_FEATURE(kIPHAutofillExternalAccountProfileSuggestionFeature);
 BASE_DECLARE_FEATURE(kIPHAutofillVirtualCardCVCSuggestionFeature);
