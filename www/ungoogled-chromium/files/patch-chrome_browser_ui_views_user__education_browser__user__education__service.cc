--- chrome/browser/ui/views/user_education/browser_user_education_service.cc.orig	2026-10-31 12:09:36 UTC
+++ chrome/browser/ui/views/user_education/browser_user_education_service.cc
@@ -321,7 +321,7 @@ CreateNavigationAction(GURL target) {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void NavigateToSettingsPage(ContextPtr ctx,
                             user_education::FeaturePromoHandle promo_handle) {
   BrowserWindowInterface* const browser = GetBrowser(ctx);
@@ -1532,7 +1532,7 @@ void MaybeRegisterChromeFeaturePromos(
                 "Triggered when a shared tab becomes the active tab.")));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // kIPHSupervisedUserProfileSigninFeature:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
@@ -1861,7 +1861,7 @@ void MaybeRegisterChromeFeaturePromos(
               "Omnibox Everywhere.")));
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // kIPHDesktopPWAsLinkCapturingLaunch:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
@@ -2714,7 +2714,7 @@ void MaybeRegisterChromeNewBadges(user_education::NewB
       user_education::Metadata(158, "xinlongyi@9oo91e.qjz9zk",
                                "Shown on the Skills item in the app menu.")));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry.RegisterFeature(user_education::NewBadgeSpecification(
       switches::kCrossDeviceSigninFromDesktop,
       user_education::Metadata(
