--- chrome/browser/ui/webui/certificate_manager/client_cert_sources.cc.orig	2024-10-27 06:40:35 UTC
+++ chrome/browser/ui/webui/certificate_manager/client_cert_sources.cc
@@ -43,7 +43,7 @@
 #include "net/ssl/client_cert_store_mac.h"
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #include "components/enterprise/client_certificates/core/certificate_provisioning_service.h"
 #include "components/enterprise/client_certificates/core/client_certificates_service.h"
@@ -191,7 +191,7 @@ std::unique_ptr<ClientCertStoreLoader> CreatePlatformC
 #endif
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // ClientCertStore implementation that always returns an empty list. The
 // CertificateProvisioningService implementation expects to wrap a platform
 // cert store, but here we only want to get results from the provisioning
@@ -673,7 +673,7 @@ CreatePlatformClientCertSource(
 #endif
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<CertificateManagerPageHandler::CertSource>
 CreateProvisionedClientCertSource(Profile* profile) {
   return std::make_unique<ClientCertSource>(
