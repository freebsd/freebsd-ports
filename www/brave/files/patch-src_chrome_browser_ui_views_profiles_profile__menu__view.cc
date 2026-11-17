--- src/chrome/browser/ui/views/profiles/profile_menu_view.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/views/profiles/profile_menu_view.cc
@@ -112,7 +112,7 @@
 #include "chrome/browser/signin/cross_device_signin_promo_manager.h"
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #endif
 
@@ -574,7 +574,7 @@ void ProfileMenuView::SetMenuTitleForAcc
     case signin_util::SignedInState::kSignedOut:
     case signin_util::SignedInState::kWebOnlySignedIn: {
       std::string profile_user_display_name, profile_user_email;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       profile_user_display_name = profile().GetPrefs()->GetString(
           enterprise_signin::prefs::kProfileUserDisplayName);
       profile_user_email = profile().GetPrefs()->GetString(
