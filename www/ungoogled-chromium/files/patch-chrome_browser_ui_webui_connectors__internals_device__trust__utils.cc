--- chrome/browser/ui/webui/connectors_internals/device_trust_utils.cc.orig	2026-04-15 11:25:12 UTC
+++ chrome/browser/ui/webui/connectors_internals/device_trust_utils.cc
@@ -9,7 +9,7 @@
 #include "components/enterprise/connectors/core/connectors_internals_utils.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
@@ -31,7 +31,7 @@ namespace enterprise_connectors::utils {
 namespace {
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 
 connectors_internals::mojom::KeyTrustLevel ParseTrustLevel(
     BPKUR::KeyTrustLevel trust_level) {
@@ -74,7 +74,7 @@ connectors_internals::mojom::KeyManagerPermanentFailur
 
 connectors_internals::mojom::KeyInfoPtr GetKeyInfo() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   auto* key_manager = g_browser_process->browser_policy_connector()
                           ->chrome_browser_cloud_management_controller()
                           ->GetDeviceTrustKeyManager();
