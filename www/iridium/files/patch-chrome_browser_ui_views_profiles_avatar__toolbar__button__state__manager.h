--- chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.h.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.h
@@ -272,7 +272,7 @@ class AvatarToolbarButtonStateManager
 
   // Shared IPH methods.
   void MaybeShowProfileSwitchIPH();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH();
   void MaybeShowSignInBenefitsIPH();
 #endif
