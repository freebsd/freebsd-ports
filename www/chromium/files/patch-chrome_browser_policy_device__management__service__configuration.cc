--- chrome/browser/policy/device_management_service_configuration.cc.orig	2021-01-18 21:28:50 UTC
+++ chrome/browser/policy/device_management_service_configuration.cc
@@ -18,7 +18,7 @@
 #endif
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID))
+    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID)) || defined(OS_BSD)
 #include "chrome/browser/enterprise/connectors/common.h"
 #include "chrome/browser/enterprise/connectors/connectors_manager.h"
 #endif
@@ -95,7 +95,7 @@ DeviceManagementServiceConfiguration::GetEncryptedRepo
 std::string
 DeviceManagementServiceConfiguration::GetReportingConnectorServerUrl() {
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID))
+    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID)) || defined(OS_BSD)
   auto settings =
       enterprise_connectors::ConnectorsManager::GetInstance()
           ->GetReportingSettings(
