--- chrome/browser/signin/accounts_policy_manager.cc.orig	2025-02-19 07:43:18 UTC
+++ chrome/browser/signin/accounts_policy_manager.cc
@@ -40,7 +40,7 @@
 #include "chrome/browser/ui/webui/profile_helper.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/policy/core/common/features.h"
 #include "components/signin/public/identity_manager/accounts_mutator.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -208,7 +208,7 @@ void AccountsPolicyManager::Initialize() {
           &AccountsPolicyManager::OnGoogleServicesUsernamePatternChanged,
           weak_pointer_factory_.GetWeakPtr()));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* identity_manager = IdentityManagerFactory::GetForProfile(profile_);
   identity_manager_observation_.Observe(identity_manager);
   profile_pref_change_registrar_.Init(profile_->GetPrefs());
@@ -223,7 +223,7 @@ void AccountsPolicyManager::Initialize() {
 }
 
 void AccountsPolicyManager::Shutdown() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   profile_pref_change_registrar_.RemoveAll();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
   local_state_pref_registrar_.RemoveAll();
@@ -340,7 +340,7 @@ void AccountsPolicyManager::OnUserConfirmedProfileDele
 }
 #endif  // defined(TOOLKIT_VIEWS) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AccountsPolicyManager::OnRefreshTokensLoaded() {
   RemoveUnallowedAccounts();
   identity_manager_observation_.Reset();
