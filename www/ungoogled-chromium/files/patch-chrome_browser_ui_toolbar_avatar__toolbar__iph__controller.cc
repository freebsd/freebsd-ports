--- chrome/browser/ui/toolbar/avatar_toolbar_iph_controller.cc.orig	2026-11-17 11:49:09 UTC
+++ chrome/browser/ui/toolbar/avatar_toolbar_iph_controller.cc
@@ -122,7 +122,7 @@ void AvatarToolbarIphController::MaybeShowSupervisedUs
 }
 
 void AvatarToolbarIphController::MaybeShowSupervisedUserProfileSignInIPHImpl() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
@@ -173,7 +173,7 @@ void AvatarToolbarIphController::MaybeShowSignInBenefi
 }
 
 void AvatarToolbarIphController::MaybeShowSignInBenefitsIPHImpl() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
