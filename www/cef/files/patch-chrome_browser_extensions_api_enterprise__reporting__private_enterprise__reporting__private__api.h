--- chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.h.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.h
@@ -16,7 +16,7 @@
 #include "chrome/browser/extensions/api/enterprise_reporting_private/chrome_desktop_report_request_helper.h"
 #include "chrome/common/extensions/api/enterprise_reporting_private.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/time/time.h"
 #include "components/device_signals/core/browser/signals_types.h"
 #endif
@@ -52,7 +52,7 @@ class EnterpriseReportingPrivateGetDeviceIdFunction : 
   ~EnterpriseReportingPrivateGetDeviceIdFunction() override;
 };
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 
 class EnterpriseReportingPrivateGetPersistentSecretFunction
     : public ExtensionFunction {
@@ -211,7 +211,7 @@ class EnterpriseReportingPrivateGetCertificateFunction
       client_cert_fetcher_;
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 class EnterpriseReportingPrivateGetFileSystemInfoFunction
     : public ExtensionFunction {
