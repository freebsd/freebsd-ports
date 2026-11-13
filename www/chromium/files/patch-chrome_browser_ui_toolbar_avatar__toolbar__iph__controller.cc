--- chrome/browser/ui/toolbar/avatar_toolbar_iph_controller.cc.orig	2026-11-11 14:44:17 UTC
+++ chrome/browser/ui/toolbar/avatar_toolbar_iph_controller.cc
@@ -123,7 +123,7 @@ void AvatarToolbarIphController::MaybeShowSupervisedUs
 }
 
 void AvatarToolbarIphController::MaybeShowSupervisedUserProfileSignInIPHImpl() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
@@ -174,7 +174,7 @@ void AvatarToolbarIphController::MaybeShowSignInBenefi
 }
 
 void AvatarToolbarIphController::MaybeShowSignInBenefitsIPHImpl() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
