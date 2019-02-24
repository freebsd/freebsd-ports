--- chrome/browser/policy/machine_level_user_cloud_policy_controller.cc.orig	2019-02-06 22:26:05.674129000 +0100
+++ chrome/browser/policy/machine_level_user_cloud_policy_controller.cc	2019-02-06 22:26:54.109036000 +0100
@@ -65,7 +65,7 @@
 #endif
 }
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 void CleanupUnusedPolicyDirectory() {
   std::string enrollment_token =
       BrowserDMTokenStorage::Get()->RetrieveEnrollmentToken();
@@ -124,7 +124,7 @@
 void MachineLevelUserCloudPolicyController::Init(
     PrefService* local_state,
     scoped_refptr<network::SharedURLLoaderFactory> url_loader_factory) {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   // This is a function that removes the directory we accidentally create due to
   // crbug.com/880870. The directory is only removed when it's empty and
   // enrollment token doesn't exist. This function is expected to be removed
