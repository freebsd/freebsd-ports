--- chrome/browser/ui/views/profiles/avatar_toolbar_button.cc.orig	2026-01-16 14:21:21 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.cc
@@ -407,7 +407,7 @@ void AvatarToolbarButton::MaybeShowProfileSwitchIPH() 
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   if (!base::FeatureList::IsEnabled(
           feature_engagement::kIPHSupervisedUserProfileSigninFeature)) {
