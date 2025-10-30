--- chrome/browser/net/profile_network_context_service.cc.orig	2025-10-30 15:44:36 UTC
+++ chrome/browser/net/profile_network_context_service.cc
@@ -143,7 +143,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
@@ -293,7 +293,7 @@ void UpdateCookieSettings(Profile* profile, ContentSet
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 std::unique_ptr<net::ClientCertStore> GetWrappedCertStore(
     Profile* profile,
     std::unique_ptr<net::ClientCertStore> platform_store) {
@@ -1269,7 +1269,7 @@ ProfileNetworkContextService::CreateClientCertStore() 
       std::make_unique<net::ClientCertStoreNSS>(
           base::BindRepeating(&CreateCryptoModuleBlockingPasswordDelegate,
                               kCryptoModulePasswordClientAuth));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GetWrappedCertStore(profile_, std::move(store));
 #else
   return store;
