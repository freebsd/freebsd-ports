--- chrome/browser/ui/webui/certificate_manager/client_cert_sources.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/webui/certificate_manager/client_cert_sources.cc
@@ -54,7 +54,7 @@
 #include "net/ssl/client_cert_store_mac.h"
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -129,7 +129,7 @@ class ClientCertStoreLoader {
       active_requests_;
 };
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class ClientCertStoreFactoryNSS : public ClientCertStoreFactory {
  public:
   std::unique_ptr<net::ClientCertStore> CreateClientCertStore() override {
@@ -154,7 +154,7 @@ class ClientCertStoreFactoryMac : public ClientCertSto
 };
 #endif
 
-#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 std::unique_ptr<ClientCertStoreLoader> CreatePlatformClientCertLoader(
     Profile* profile) {
 #if BUILDFLAG(IS_WIN)
@@ -169,7 +169,7 @@ std::unique_ptr<ClientCertStoreLoader> CreatePlatformC
 }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class ClientCertStoreFactoryProvisioned : public ClientCertStoreFactory {
  public:
   explicit ClientCertStoreFactoryProvisioned(
@@ -325,7 +325,7 @@ class ClientCertSource : public CertificateManagerPage
   std::optional<net::CertificateList> certs_;
 };
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // ChromeOS currently can use either Kcer or NSS for listing client certs, and
 // Linux uses NSS only. This interface provides an abstraction to hide that
 // from WritableClientCertSource. Currently this class only handles reading
@@ -1047,7 +1047,7 @@ CreatePlatformClientCertSource(
     mojo::Remote<certificate_manager::mojom::CertificateManagerPage>*
         remote_client,
     Profile* profile) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<WritableClientCertSource>(remote_client, profile);
 #else
   return std::make_unique<ClientCertSource>(
@@ -1055,7 +1055,7 @@ CreatePlatformClientCertSource(
 #endif
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<CertificateManagerPageHandler::CertSource>
 CreateProvisionedClientCertSource(Profile* profile) {
   return std::make_unique<ClientCertSource>(
@@ -1105,7 +1105,7 @@ bool ClientCertManagementAccessControls::IsChangeAllow
 
   return client_cert_policy_ == ClientCertificateManagementPermission::kAll;
 }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 ClientCertManagementAccessControls::ClientCertManagementAccessControls(
     Profile* profile) {}
 
