--- chrome/browser/ui/views/profiles/avatar_toolbar_button.h.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.h
@@ -91,7 +91,7 @@ class AvatarToolbarButton : public ToolbarButton {
   // Attempts showing the In-Produce-Help for profile Switching.
   void MaybeShowProfileSwitchIPH();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Attempts showing the In-Produce-Help when a supervised user signs-in in a
   // profile.
   void MaybeShowSupervisedUserSignInIPH();
