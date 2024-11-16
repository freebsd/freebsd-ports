--- components/feature_engagement/public/feature_list.cc.orig	2024-11-14 07:57:23 UTC
+++ components/feature_engagement/public/feature_list.cc
@@ -162,7 +162,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHiOSLensOverlayEntrypointTipFeature,
 #endif  // BUILDFLAG(IS_IOS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
     &kEsbDownloadRowPromoFeature,
 #endif
@@ -230,7 +230,8 @@ const base::Feature* const kAllFeatures[] = {
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
     &kIPHAutofillCreditCardBenefitFeature,
     &kIPHAutofillDisabledVirtualCardSuggestionFeature,
     &kIPHAutofillExternalAccountProfileSuggestionFeature,
@@ -282,7 +283,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHScalableIphGamingFeature,
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     &kIPHDesktopPWAsLinkCapturingLaunch,
     &kIPHToolbarManagementButtonFeature,
 #endif  // BUILDFLAG(IS_WIN) ||  BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
