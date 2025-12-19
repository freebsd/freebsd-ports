--- src/3rdparty/chromium/chrome/browser/net/profile_network_context_service.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/chrome/browser/net/profile_network_context_service.cc
@@ -134,7 +134,7 @@
 #include "extensions/common/constants.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #include "components/enterprise/client_certificates/core/certificate_provisioning_service.h"
 #include "components/enterprise/client_certificates/core/client_certificates_service.h"
@@ -261,7 +261,7 @@ void UpdateCookieSettings(Profile* profile, ContentSet
       });
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<net::ClientCertStore> GetWrappedCertStore(
     Profile* profile,
     std::unique_ptr<net::ClientCertStore> platform_store) {
@@ -1202,7 +1202,7 @@ ProfileNetworkContextService::CreateClientCertStore() 
       std::make_unique<net::ClientCertStoreNSS>(
           base::BindRepeating(&CreateCryptoModuleBlockingPasswordDelegate,
                               kCryptoModulePasswordClientAuth));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GetWrappedCertStore(profile_, std::move(store));
 #else
   return store;
