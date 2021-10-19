--- chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc.orig	2021-09-24 18:20:01 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc
@@ -13,9 +13,9 @@
 #include "components/keyed_service/content/browser_context_dependency_manager.h"
 #include "components/keyed_service/core/keyed_service.h"
 #include "content/public/browser/browser_context.h"
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/attestation/desktop/desktop_attestation_service.h"
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
 #include "chrome/browser/enterprise/connectors/device_trust/attestation/ash/ash_attestation_service.h"
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
