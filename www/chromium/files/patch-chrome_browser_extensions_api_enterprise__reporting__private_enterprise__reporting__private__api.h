--- chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.h.orig	2021-12-14 11:44:58 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.h
@@ -45,7 +45,7 @@ class EnterpriseReportingPrivateGetDeviceIdFunction : 
   ~EnterpriseReportingPrivateGetDeviceIdFunction() override;
 };
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 
 class EnterpriseReportingPrivateGetPersistentSecretFunction
     : public ExtensionFunction {
@@ -73,7 +73,7 @@ class EnterpriseReportingPrivateGetPersistentSecretFun
   void SendResponse(const std::string& data, long int status);
 };
 
-#endif  // !defined(OS_LINUX)
+#endif  // !defined(OS_LINUX) && !defined(OS_BSD)
 
 class EnterpriseReportingPrivateGetDeviceDataFunction
     : public ExtensionFunction {
