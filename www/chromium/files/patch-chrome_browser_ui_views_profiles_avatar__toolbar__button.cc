--- chrome/browser/ui/views/profiles/avatar_toolbar_button.cc.orig	2025-07-02 06:08:04 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.cc
@@ -317,7 +317,7 @@ void AvatarToolbarButton::MaybeShowProfileSwitchIPH() 
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   if (!base::FeatureList::IsEnabled(
           feature_engagement::kIPHSupervisedUserProfileSigninFeature)) {
