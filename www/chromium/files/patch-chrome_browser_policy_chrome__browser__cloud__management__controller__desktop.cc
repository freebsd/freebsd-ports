--- chrome/browser/policy/chrome_browser_cloud_management_controller_desktop.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/policy/chrome_browser_cloud_management_controller_desktop.cc
@@ -46,7 +46,7 @@
 #include "chrome/browser/policy/browser_dm_token_storage_mac.h"
 #endif  // defined(OS_MAC)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/policy/browser_dm_token_storage_linux.h"
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
 
@@ -55,7 +55,7 @@
 #include "chrome/install_static/install_util.h"
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_features.h"
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/device_trust_key_manager_impl.h"
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/key_rotation_launcher.h"
@@ -88,7 +88,7 @@ void ChromeBrowserCloudManagementControllerDesktop::
 
 #if defined(OS_MAC)
   storage_delegate = std::make_unique<BrowserDMTokenStorageMac>();
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   storage_delegate = std::make_unique<BrowserDMTokenStorageLinux>();
 #elif defined(OS_WIN)
   storage_delegate = std::make_unique<BrowserDMTokenStorageWin>();
@@ -243,7 +243,7 @@ ChromeBrowserCloudManagementControllerDesktop::CreateC
 
 std::unique_ptr<enterprise_connectors::DeviceTrustKeyManager>
 ChromeBrowserCloudManagementControllerDesktop::CreateDeviceTrustKeyManager() {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
   if (enterprise_connectors::IsDeviceTrustConnectorFeatureEnabled()) {
     auto key_rotation_launcher =
         enterprise_connectors::KeyRotationLauncher::Create(
