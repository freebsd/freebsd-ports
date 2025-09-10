--- chrome/browser/ui/views/user_education/browser_user_education_service.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/ui/views/user_education/browser_user_education_service.cc
@@ -1057,7 +1057,7 @@ void MaybeRegisterChromeFeaturePromos(
                 "Triggered when a shared tab becomes the active tab.")));
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // kIPHSupervisedUserProfileSigninFeature
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
@@ -1304,7 +1304,7 @@ void MaybeRegisterChromeFeaturePromos(
                        "Triggered to inform users of the availability of the "
                        "new translate screen feature on the Lens Overlay.")));
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // kIPHDesktopPWAsLinkCapturingLaunch:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
