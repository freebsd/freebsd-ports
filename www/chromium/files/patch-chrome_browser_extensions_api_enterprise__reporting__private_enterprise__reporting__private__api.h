--- chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.h.orig	2021-09-24 18:21:41 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.h
@@ -41,7 +41,7 @@ class EnterpriseReportingPrivateGetDeviceIdFunction : 
   DISALLOW_COPY_AND_ASSIGN(EnterpriseReportingPrivateGetDeviceIdFunction);
 };
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 
 class EnterpriseReportingPrivateGetPersistentSecretFunction
     : public ExtensionFunction {
@@ -69,7 +69,7 @@ class EnterpriseReportingPrivateGetPersistentSecretFun
   void SendResponse(const std::string& data, long int status);
 };
 
-#endif  // !defined(OS_LINUX)
+#endif  // !defined(OS_LINUX) && !defined(OS_BSD)
 
 class EnterpriseReportingPrivateGetDeviceDataFunction
     : public ExtensionFunction {
