--- chrome/browser/net/profile_network_context_service.cc.orig	2025-02-20 09:59:21 UTC
+++ chrome/browser/net/profile_network_context_service.cc
@@ -144,7 +144,7 @@
 #include "chromeos/startup/browser_params_proxy.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #include "components/enterprise/client_certificates/core/certificate_provisioning_service.h"
 #include "components/enterprise/client_certificates/core/client_certificates_service.h"
@@ -271,7 +271,7 @@ void UpdateCookieSettings(Profile* profile, ContentSet
       });
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<net::ClientCertStore> GetWrappedCertStore(
     Profile* profile,
     std::unique_ptr<net::ClientCertStore> platform_store) {
@@ -1223,7 +1223,7 @@ ProfileNetworkContextService::CreateClientCertStore() 
   store = std::make_unique<ClientCertStoreLacros>(
       std::move(certificate_provider), cert_db_initializer, std::move(store));
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GetWrappedCertStore(profile_, std::move(store));
 #else
   return store;
