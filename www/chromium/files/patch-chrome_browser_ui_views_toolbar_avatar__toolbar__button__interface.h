--- chrome/browser/ui/views/toolbar/avatar_toolbar_button_interface.h.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/ui/views/toolbar/avatar_toolbar_button_interface.h
@@ -83,7 +83,7 @@ class AvatarToolbarButtonInterface {
   // Attempts showing the In-Product-Help for profile Switching.
   virtual void MaybeShowProfileSwitchIPH() = 0;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Attempts showing the In-Product-Help when a supervised user signs-in in a
   // profile.
   virtual void MaybeShowSupervisedUserSignInIPH() = 0;
