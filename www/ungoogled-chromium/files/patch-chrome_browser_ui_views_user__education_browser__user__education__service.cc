--- chrome/browser/ui/views/user_education/browser_user_education_service.cc.orig	2025-02-20 09:59:21 UTC
+++ chrome/browser/ui/views/user_education/browser_user_education_service.cc
@@ -893,7 +893,7 @@ void MaybeRegisterChromeFeaturePromos(
                          "defaulted to saved for the first time.")));
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // kIPHSupervisedUserProfileSigninFeature
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
@@ -1134,7 +1134,7 @@ void MaybeRegisterChromeFeaturePromos(
                        "Triggered to inform users of the availability of the "
                        "new translate screen feature on the Lens Overlay.")));
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // kIPHDesktopPWAsLinkCapturingLaunch:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
