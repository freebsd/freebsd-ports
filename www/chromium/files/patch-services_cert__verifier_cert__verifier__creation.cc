--- services/cert_verifier/cert_verifier_creation.cc.orig	2022-06-17 14:20:10 UTC
+++ services/cert_verifier/cert_verifier_creation.cc
@@ -12,7 +12,7 @@
 #include "net/cert_net/cert_net_fetcher_url_request.h"
 #include "net/net_buildflags.h"
 
-#if BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED) || \
+#if BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 #include "net/cert/cert_verify_proc_builtin.h"
 #include "net/cert/internal/system_trust_store.h"
@@ -94,7 +94,7 @@ class OldDefaultCertVerifyProcFactory : public net::Ce
       scoped_refptr<net::CertNetFetcher> cert_net_fetcher,
       const net::ChromeRootStoreData* root_store_data) override {
     scoped_refptr<net::CertVerifyProc> verify_proc;
-#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     verify_proc = net::CreateCertVerifyProcBuiltin(
         std::move(cert_net_fetcher), net::CreateSslSystemTrustStore());
 #else
@@ -272,6 +272,7 @@ std::unique_ptr<net::CertVerifierWithUpdatableProc> Cr
 bool IsUsingCertNetFetcher() {
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) ||      \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||       \
+    BUILDFLAG(IS_BSD) ||                                   \
     BUILDFLAG(TRIAL_COMPARISON_CERT_VERIFIER_SUPPORTED) || \
     BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED) ||  \
     BUILDFLAG(CHROME_ROOT_STORE_SUPPORTED)
