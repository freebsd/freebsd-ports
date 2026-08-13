--- chrome/browser/ui/views/user_education/browser_user_education_service.cc.orig	2026-08-12 09:02:10 UTC
+++ chrome/browser/ui/views/user_education/browser_user_education_service.cc
@@ -289,7 +289,7 @@ CreateNavigationAction(GURL target) {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void NavigateToSettingsPage(ContextPtr ctx,
                             user_education::FeaturePromoHandle promo_handle) {
   BrowserWindowInterface* const browser = GetBrowser(ctx);
@@ -1481,7 +1481,7 @@ void MaybeRegisterChromeFeaturePromos(
                 "Triggered when a shared tab becomes the active tab.")));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // kIPHSupervisedUserProfileSigninFeature:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
@@ -1774,7 +1774,7 @@ void MaybeRegisterChromeFeaturePromos(
                        "new translate screen feature on the Lens Overlay.")));
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // kIPHDesktopPWAsLinkCapturingLaunch:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
@@ -2507,7 +2507,7 @@ void MaybeRegisterChromeNewBadges(user_education::NewB
           151, "mtatarski@google.com",
           "Show the new badge on Send to Your Devices context menu items.")));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry.RegisterFeature(user_education::NewBadgeSpecification(
       switches::kCrossDeviceSigninFromDesktop,
       user_education::Metadata(
