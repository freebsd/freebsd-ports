--- chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc
@@ -21,7 +21,7 @@
 #include "components/policy/content/policy_blocklist_service.h"
 #include "content/public/browser/browser_context.h"
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/enterprise/connectors/device_trust/attestation/desktop/desktop_attestation_service.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
