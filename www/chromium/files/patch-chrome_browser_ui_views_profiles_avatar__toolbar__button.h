--- chrome/browser/ui/views/profiles/avatar_toolbar_button.h.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.h
@@ -97,7 +97,7 @@ class AvatarToolbarButton : public ToolbarButton,
   // Attempts showing the In-Product-Help for profile Switching.
   void MaybeShowProfileSwitchIPH();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Attempts showing the In-Product-Help when a supervised user signs-in in a
   // profile.
   void MaybeShowSupervisedUserSignInIPH();
