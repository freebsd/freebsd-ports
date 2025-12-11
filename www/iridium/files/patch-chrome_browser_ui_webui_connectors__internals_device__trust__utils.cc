--- chrome/browser/ui/webui/connectors_internals/device_trust_utils.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/ui/webui/connectors_internals/device_trust_utils.cc
@@ -8,7 +8,7 @@
 #include "components/enterprise/buildflags/buildflags.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "base/base64url.h"
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -42,7 +42,7 @@ namespace enterprise_connectors::utils {
 namespace {
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 
 connectors_internals::mojom::KeyTrustLevel ParseTrustLevel(
     BPKUR::KeyTrustLevel trust_level) {
@@ -182,7 +182,7 @@ connectors_internals::mojom::CertificateMetadataPtr Co
 
 connectors_internals::mojom::KeyInfoPtr GetKeyInfo() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   auto* key_manager = g_browser_process->browser_policy_connector()
                           ->chrome_browser_cloud_management_controller()
                           ->GetDeviceTrustKeyManager();
