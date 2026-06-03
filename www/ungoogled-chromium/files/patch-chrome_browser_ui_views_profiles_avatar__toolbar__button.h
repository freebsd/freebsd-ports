--- chrome/browser/ui/views/profiles/avatar_toolbar_button.h.orig	2026-04-15 11:25:12 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.h
@@ -99,7 +99,7 @@ class AvatarToolbarButton : public ToolbarButton,
   // Attempts showing the In-Product-Help for profile Switching.
   void MaybeShowProfileSwitchIPH();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Attempts showing the In-Product-Help when a supervised user signs-in in a
   // profile.
   void MaybeShowSupervisedUserSignInIPH();
