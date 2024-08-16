--- chrome/browser/ui/views/user_education/browser_user_education_service.cc.orig	2024-07-31 14:19:23 UTC
+++ chrome/browser/ui/views/user_education/browser_user_education_service.cc
@@ -996,7 +996,7 @@ void MaybeRegisterChromeFeaturePromos(
                     FeaturePromoSpecification::AcceleratorInfo())
                     .SetBubbleArrow(HelpBubbleArrow::kTopLeft)));
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // kIPHDesktopPWAsLinkCapturingLaunch:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
