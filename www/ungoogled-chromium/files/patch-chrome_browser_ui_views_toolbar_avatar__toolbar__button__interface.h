--- chrome/browser/ui/views/toolbar/avatar_toolbar_button_interface.h.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/ui/views/toolbar/avatar_toolbar_button_interface.h
@@ -76,7 +76,7 @@ class AvatarToolbarButtonInterface {
   // Attempts showing the In-Product-Help for profile Switching.
   virtual void MaybeShowProfileSwitchIPH() = 0;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Attempts showing the In-Product-Help when a supervised user signs-in in a
   // profile.
   virtual void MaybeShowSupervisedUserSignInIPH() = 0;
