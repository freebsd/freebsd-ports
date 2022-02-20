--- chrome/browser/ui/webui/connectors_internals/zero_trust_utils.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/ui/webui/connectors_internals/zero_trust_utils.cc
@@ -9,7 +9,7 @@
 #include "base/strings/string_util.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
@@ -66,7 +66,7 @@ void TrySetSignal(base::flat_map<std::string, std::str
       std::vector<base::StringPiece>(values.begin(), values.end()), ", ");
 }
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 
 connectors_internals::mojom::KeyTrustLevel ParseTrustLevel(
     BPKUR::KeyTrustLevel trust_level) {
@@ -171,7 +171,7 @@ base::flat_map<std::string, std::string> SignalsToMap(
 }
 
 connectors_internals::mojom::KeyInfoPtr GetKeyInfo() {
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   auto* key_manager = g_browser_process->browser_policy_connector()
                           ->chrome_browser_cloud_management_controller()
                           ->GetDeviceTrustKeyManager();
