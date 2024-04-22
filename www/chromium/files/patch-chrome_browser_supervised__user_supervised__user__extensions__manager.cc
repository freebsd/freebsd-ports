--- chrome/browser/supervised_user/supervised_user_extensions_manager.cc.orig	2024-04-19 13:02:56 UTC
+++ chrome/browser/supervised_user/supervised_user_extensions_manager.cc
@@ -305,7 +305,7 @@ void SupervisedUserExtensionsManager::
     ActivateManagementPolicyAndUpdateRegistration() {
   SetActiveForSupervisedUsers();
   UpdateManagementPolicyRegistration();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MaybeMarkExtensionsLocallyParentApproved();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 }
@@ -417,7 +417,7 @@ bool SupervisedUserExtensionsManager::ShouldBlockExten
   return false;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SupervisedUserExtensionsManager::
     MaybeMarkExtensionsLocallyParentApproved() {
   if (!is_active_policy_for_supervised_users_) {
