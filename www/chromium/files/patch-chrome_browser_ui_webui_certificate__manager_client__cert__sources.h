--- chrome/browser/ui/webui/certificate_manager/client_cert_sources.h.orig	2024-09-30 07:45:04 UTC
+++ chrome/browser/ui/webui/certificate_manager/client_cert_sources.h
@@ -17,7 +17,7 @@ CreatePlatformClientCertSource(
     mojo::Remote<certificate_manager_v2::mojom::CertificateManagerPage>*
         remote_client);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<CertificateManagerPageHandler::CertSource>
 CreateProvisionedClientCertSource(Profile* profile);
 #endif
