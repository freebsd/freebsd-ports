--- src/chrome/browser/net/profile_network_context_service.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/net/profile_network_context_service.cc
@@ -147,7 +147,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
@@ -326,7 +326,7 @@ void UpdateCookieSettings(Profile* profi
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 std::unique_ptr<net::ClientCertStore> GetWrappedCertStore(
     Profile* profile,
     std::unique_ptr<net::ClientCertStore> platform_store) {
@@ -1293,7 +1293,7 @@ ProfileNetworkContextService::CreateClie
       std::make_unique<net::ClientCertStoreNSS>(
           base::BindRepeating(&CreateCryptoModuleBlockingPasswordDelegate,
                               kCryptoModulePasswordClientAuth));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GetWrappedCertStore(profile_, std::move(store));
 #else
   return store;
