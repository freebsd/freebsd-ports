--- chrome/browser/policy/device_management_service_configuration.cc.orig	2020-11-16 14:22:12 UTC
+++ chrome/browser/policy/device_management_service_configuration.cc
@@ -18,7 +18,7 @@
 #endif
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID))
+    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID)) || defined(OS_BSD)
 #include "chrome/browser/enterprise/connectors/common.h"
 #include "chrome/browser/enterprise/connectors/connectors_manager.h"
 #endif
@@ -86,7 +86,7 @@ std::string DeviceManagementServiceConfiguration::GetR
 std::string
 DeviceManagementServiceConfiguration::GetReportingConnectorServerUrl() {
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID))
+    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID)) || defined(OS_BSD)
   auto settings =
       enterprise_connectors::ConnectorsManager::GetInstance()
           ->GetReportingSettings(
