--- chrome/browser/signin/primary_account_policy_manager.cc.orig	2022-06-17 14:20:10 UTC
+++ chrome/browser/signin/primary_account_policy_manager.cc
@@ -23,7 +23,7 @@
 #include "google_apis/gaia/gaia_auth_util.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/profiles/profile_manager.h"
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_finder.h"
@@ -35,7 +35,7 @@
 #include "chrome/browser/ui/webui/profile_helper.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // Manager that presents the profile will be deleted dialog on the first active
 // browser window.
 class PrimaryAccountPolicyManager::DeleteProfileDialogManager
@@ -250,7 +250,7 @@ void PrimaryAccountPolicyManager::EnsurePrimaryAccount
       break;
     }
     case signin::Tribool::kFalse:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       // Force remove the profile if sign out is not allowed and if the
       // primary account is no longer allowed.
       // This may be called while the profile is initializing, so it must be
@@ -281,7 +281,7 @@ void PrimaryAccountPolicyManager::EnsurePrimaryAccount
 #endif  // !BUILDFLAG(IS_CHROMEOS_ASH)
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // Shows the delete profile dialog on the first browser active window.
 void PrimaryAccountPolicyManager::ShowDeleteProfileDialog(
     Profile* profile,
