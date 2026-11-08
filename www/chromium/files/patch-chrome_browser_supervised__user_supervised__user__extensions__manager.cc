--- chrome/browser/supervised_user/supervised_user_extensions_manager.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/supervised_user/supervised_user_extensions_manager.cc
@@ -346,7 +346,7 @@ void SupervisedUserExtensionsManager::
     ActivateManagementPolicyAndUpdateRegistration() {
   SetActiveForSupervisedUsers();
   UpdateManagementPolicyRegistration();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MaybeMarkExtensionsLocallyParentApproved();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 }
@@ -446,7 +446,7 @@ bool SupervisedUserExtensionsManager::ShouldBlockExten
   return false;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SupervisedUserExtensionsManager::
     MaybeMarkExtensionsLocallyParentApproved() {
   supervised_user::LocallyParentApprovedExtensionsMigrationState
