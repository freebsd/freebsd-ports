--- chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.h.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.h
@@ -270,7 +270,7 @@ class AvatarToolbarButtonStateManager
 
   // Shared IPH methods.
   void MaybeShowProfileSwitchIPH();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH();
   void MaybeShowSignInBenefitsIPH();
 #endif
