--- src/3rdparty/chromium/components/feature_engagement/public/feature_constants.h.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/components/feature_engagement/public/feature_constants.h
@@ -20,7 +20,7 @@ BASE_DECLARE_FEATURE(kIPHDemoMode);
 BASE_DECLARE_FEATURE(kIPHDummyFeature);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 BASE_DECLARE_FEATURE(kEsbDownloadRowPromoFeature);
 #endif
@@ -258,7 +258,8 @@ BASE_DECLARE_FEATURE(kDefaultBrowserTriggerCriteriaExp
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHAutofillCreditCardBenefitFeature);
 BASE_DECLARE_FEATURE(kIPHAutofillDisabledVirtualCardSuggestionFeature);
 BASE_DECLARE_FEATURE(kIPHAutofillExternalAccountProfileSuggestionFeature);
@@ -309,7 +310,7 @@ BASE_DECLARE_FEATURE(kIPHScalableIphHelpAppBasedTenFea
 BASE_DECLARE_FEATURE(kIPHScalableIphGamingFeature);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHDesktopPWAsLinkCapturingLaunch);
 BASE_DECLARE_FEATURE(kIPHToolbarManagementButtonFeature);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
