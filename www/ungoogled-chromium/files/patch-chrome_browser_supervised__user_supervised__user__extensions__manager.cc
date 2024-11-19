--- chrome/browser/supervised_user/supervised_user_extensions_manager.cc.orig	2024-11-16 12:20:41 UTC
+++ chrome/browser/supervised_user/supervised_user_extensions_manager.cc
@@ -357,7 +357,7 @@ void SupervisedUserExtensionsManager::
     ActivateManagementPolicyAndUpdateRegistration() {
   SetActiveForSupervisedUsers();
   UpdateManagementPolicyRegistration();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MaybeMarkExtensionsLocallyParentApproved();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 }
@@ -475,7 +475,7 @@ bool SupervisedUserExtensionsManager::ShouldBlockExten
   return false;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SupervisedUserExtensionsManager::
     MaybeMarkExtensionsLocallyParentApproved() {
   supervised_user::LocallyParentApprovedExtensionsMigrationState
