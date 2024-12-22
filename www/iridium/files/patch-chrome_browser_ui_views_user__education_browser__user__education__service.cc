--- chrome/browser/ui/views/user_education/browser_user_education_service.cc.orig	2024-12-22 12:24:29 UTC
+++ chrome/browser/ui/views/user_education/browser_user_education_service.cc
@@ -845,7 +845,7 @@ void MaybeRegisterChromeFeaturePromos(
                          "defaulted to saved for the first time.")));
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // kIPHSupervisedUserProfileSigninFeature
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
@@ -1085,7 +1085,7 @@ void MaybeRegisterChromeFeaturePromos(
                        "Triggered to inform users of the availability of the "
                        "new translate screen feature on the Lens Overlay.")));
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // kIPHDesktopPWAsLinkCapturingLaunch:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
