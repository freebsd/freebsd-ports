--- chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.h.orig	2022-12-06 08:09:13 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.h
@@ -19,7 +19,7 @@
 #include "components/reporting/proto/synced/record.pb.h"
 #include "components/reporting/proto/synced/record_constants.pb.h"
 #include "components/reporting/util/statusor.h"
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/time/time.h"
 #include "components/device_signals/core/browser/signals_types.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
@@ -55,7 +55,7 @@ class EnterpriseReportingPrivateGetDeviceIdFunction : 
   ~EnterpriseReportingPrivateGetDeviceIdFunction() override;
 };
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 
 class EnterpriseReportingPrivateGetPersistentSecretFunction
     : public ExtensionFunction {
@@ -265,7 +265,7 @@ class EnterpriseReportingPrivateEnqueueRecordFunction
 
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 class EnterpriseReportingPrivateGetFileSystemInfoFunction
     : public ExtensionFunction {
