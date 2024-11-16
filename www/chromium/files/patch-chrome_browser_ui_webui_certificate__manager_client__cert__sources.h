--- chrome/browser/ui/webui/certificate_manager/client_cert_sources.h.orig	2024-11-14 07:57:23 UTC
+++ chrome/browser/ui/webui/certificate_manager/client_cert_sources.h
@@ -19,7 +19,7 @@ CreatePlatformClientCertSource(
         remote_client,
     Profile* profile);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<CertificateManagerPageHandler::CertSource>
 CreateProvisionedClientCertSource(Profile* profile);
 #endif
