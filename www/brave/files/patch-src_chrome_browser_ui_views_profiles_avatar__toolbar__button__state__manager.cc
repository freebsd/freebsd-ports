--- src/chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.cc
@@ -2675,7 +2675,7 @@ void AvatarToolbarButtonStateManager::Ma
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AvatarToolbarButtonStateManager::MaybeShowSupervisedUserSignInIPH() {
   if (!base::FeatureList::IsEnabled(
           feature_engagement::kIPHSupervisedUserProfileSigninFeature)) {
