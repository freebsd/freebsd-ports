--- chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.h.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.h
@@ -240,7 +240,7 @@ class AvatarToolbarButtonStateManager
 
   // Shared IPH methods.
   void MaybeShowProfileSwitchIPH();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH();
   void MaybeShowSignInBenefitsIPH();
 #endif
