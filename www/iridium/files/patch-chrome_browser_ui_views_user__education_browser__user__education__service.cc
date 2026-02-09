--- chrome/browser/ui/views/user_education/browser_user_education_service.cc.orig	2026-02-16 10:45:29 UTC
+++ chrome/browser/ui/views/user_education/browser_user_education_service.cc
@@ -1255,7 +1255,7 @@ void MaybeRegisterChromeFeaturePromos(
                 "Triggered when a shared tab becomes the active tab.")));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // kIPHSupervisedUserProfileSigninFeature:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
@@ -1522,7 +1522,7 @@ void MaybeRegisterChromeFeaturePromos(
                        "Triggered to inform users of the availability of the "
                        "new translate screen feature on the Lens Overlay.")));
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // kIPHDesktopPWAsLinkCapturingLaunch:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
