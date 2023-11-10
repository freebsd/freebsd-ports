--- components/feature_engagement/public/feature_list.cc.orig	2023-11-03 10:09:45 UTC
+++ components/feature_engagement/public/feature_list.cc
@@ -143,7 +143,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHiOSChoiceScreenFeature,
 #endif  // BUILDFLAG(IS_IOS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     &kIPHBatterySaverModeFeature,
     &kIPHCompanionSidePanelFeature,
     &kIPHCompanionSidePanelRegionSearchFeature,
@@ -189,7 +189,7 @@ const base::Feature* const kAllFeatures[] = {
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
     &kIPHAutofillExternalAccountProfileSuggestionFeature,
     &kIPHAutofillVirtualCardCVCSuggestionFeature,
