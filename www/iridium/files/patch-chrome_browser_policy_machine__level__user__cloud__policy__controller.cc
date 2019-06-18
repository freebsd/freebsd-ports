--- chrome/browser/policy/machine_level_user_cloud_policy_controller.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/policy/machine_level_user_cloud_policy_controller.cc
@@ -65,7 +65,7 @@ bool IsMachineLevelUserCloudPolicyEnabled() {
 #endif
 }
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 void CleanupUnusedPolicyDirectory() {
   std::string enrollment_token =
       BrowserDMTokenStorage::Get()->RetrieveEnrollmentToken();
@@ -124,7 +124,7 @@ MachineLevelUserCloudPolicyController::CreatePolicyMan
 void MachineLevelUserCloudPolicyController::Init(
     PrefService* local_state,
     scoped_refptr<network::SharedURLLoaderFactory> url_loader_factory) {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   // This is a function that removes the directory we accidentally create due to
   // crbug.com/880870. The directory is only removed when it's empty and
   // enrollment token doesn't exist. This function is expected to be removed
