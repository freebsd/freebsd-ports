--- chrome/browser/ui/views/profiles/avatar_toolbar_button.cc.orig	2026-08-12 09:02:10 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.cc
@@ -460,7 +460,7 @@ void AvatarToolbarButton::MaybeShowProfileSwitchIPH() 
   state_manager_.MaybeShowProfileSwitchIPH();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   state_manager_.MaybeShowSupervisedUserSignInIPH();
 }
