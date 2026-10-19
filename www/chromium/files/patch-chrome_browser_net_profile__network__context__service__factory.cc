--- chrome/browser/net/profile_network_context_service_factory.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/net/profile_network_context_service_factory.cc
@@ -29,7 +29,7 @@
 #include "chrome/browser/net/server_certificate_database_service_factory.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #endif
 
@@ -81,7 +81,7 @@ ProfileNetworkContextServiceFactory::ProfileNetworkCon
 #if BUILDFLAG(CHROME_ROOT_STORE_CERT_MANAGEMENT_UI)
   DependsOn(net::ServerCertificateDatabaseServiceFactory::GetInstance());
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DependsOn(client_certificates::CertificateProvisioningServiceFactory::
                 GetInstance());
 #endif
