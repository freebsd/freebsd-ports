--- chrome/browser/net/profile_network_context_service_factory.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/net/profile_network_context_service_factory.cc
@@ -32,7 +32,7 @@
 #include "chrome/browser/net/server_certificate_database_service_factory.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #endif
 
@@ -76,7 +76,7 @@ ProfileNetworkContextServiceFactory::ProfileNetworkCon
 #if BUILDFLAG(CHROME_ROOT_STORE_CERT_MANAGEMENT_UI)
   DependsOn(net::ServerCertificateDatabaseServiceFactory::GetInstance());
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DependsOn(client_certificates::CertificateProvisioningServiceFactory::
                 GetInstance());
 #endif
