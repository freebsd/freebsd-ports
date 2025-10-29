--- chrome/browser/ui/views/profiles/profile_menu_view.cc.orig	2025-10-28 14:29:43 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_view.cc
@@ -103,7 +103,7 @@
 #include "ui/views/accessibility/view_accessibility.h"
 #include "ui/views/widget/widget.h"
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #endif
 
@@ -557,7 +557,7 @@ void ProfileMenuView::SetMenuTitleForAccessibility() {
     case signin_util::SignedInState::kSignedOut:
     case signin_util::SignedInState::kWebOnlySignedIn: {
       std::string profile_user_display_name, profile_user_email;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       profile_user_display_name = profile().GetPrefs()->GetString(
           enterprise_signin::prefs::kProfileUserDisplayName);
       profile_user_email = profile().GetPrefs()->GetString(
