--- chrome/browser/ui/views/profiles/avatar_toolbar_button.h.orig	2025-10-30 15:44:36 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.h
@@ -96,7 +96,7 @@ class AvatarToolbarButton : public ToolbarButton,
   // Attempts showing the In-Product-Help for profile Switching.
   void MaybeShowProfileSwitchIPH();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Attempts showing the In-Product-Help when a supervised user signs-in in a
   // profile.
   void MaybeShowSupervisedUserSignInIPH();
