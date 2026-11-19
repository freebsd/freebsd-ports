--- chrome/browser/ui/views/user_education/browser_user_education_service.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/views/user_education/browser_user_education_service.cc
@@ -402,7 +402,7 @@ CreateNavigationAction(GURL target) {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void NavigateToSettingsPage(ContextPtr ctx,
                             user_education::FeaturePromoHandle promo_handle) {
   BrowserWindowInterface* const browser = GetBrowser(ctx);
@@ -1683,7 +1683,7 @@ void MaybeRegisterChromeFeaturePromos(
                 "Triggered when a shared tab becomes the active tab.")));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // kIPHSupervisedUserProfileSigninFeature:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
@@ -2053,7 +2053,7 @@ void MaybeRegisterChromeFeaturePromos(
               Metadata::FeatureSet{&omnibox::kWebUIOmniboxAskGAboutThisPage})));
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // kIPHDesktopPWAsLinkCapturingLaunch:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
@@ -3039,7 +3039,7 @@ void MaybeRegisterChromeNewBadges(user_education::NewB
                                "Shown on the Focus on group item in the "
                                "tab context menu.")));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry.RegisterFeature(user_education::NewBadgeSpecification(
       switches::kCrossDeviceSigninFromDesktop,
       user_education::Metadata(
