--- chrome/browser/ui/views/profiles/profile_menu_view.cc.orig	2025-02-22 18:06:53 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_view.cc
@@ -90,7 +90,7 @@
 #include "ui/strings/grit/ui_strings.h"
 #include "ui/views/accessibility/view_accessibility.h"
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #endif
 
@@ -558,7 +558,7 @@ void ProfileMenuView::SetMenuTitleForAccessibility() {
     case signin_util::SignedInState::kSignedOut:
     case signin_util::SignedInState::kWebOnlySignedIn: {
       std::string profile_user_display_name, profile_user_email;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       profile_user_display_name = profile->GetPrefs()->GetString(
           enterprise_signin::prefs::kProfileUserDisplayName);
       profile_user_email = profile->GetPrefs()->GetString(
@@ -660,7 +660,7 @@ void ProfileMenuView::BuildIdentity() {
         badge_image_model, menu_title_, menu_subtitle_, management_label);
   } else {
     std::string profile_user_display_name, profile_user_email;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     profile_user_display_name = profile->GetPrefs()->GetString(
         enterprise_signin::prefs::kProfileUserDisplayName);
     profile_user_email = profile->GetPrefs()->GetString(
