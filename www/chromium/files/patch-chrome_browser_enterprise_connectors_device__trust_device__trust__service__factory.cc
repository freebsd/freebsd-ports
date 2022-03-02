--- chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc
@@ -21,7 +21,7 @@
 #include "components/policy/content/policy_blocklist_service.h"
 #include "content/public/browser/browser_context.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/enterprise/connectors/device_trust/attestation/desktop/desktop_attestation_service.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
