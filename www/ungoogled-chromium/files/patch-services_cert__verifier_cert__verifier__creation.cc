--- services/cert_verifier/cert_verifier_creation.cc.orig	2022-12-02 17:56:32 UTC
+++ services/cert_verifier/cert_verifier_creation.cc
@@ -12,7 +12,7 @@
 #include "net/cert_net/cert_net_fetcher_url_request.h"
 #include "net/net_buildflags.h"
 
-#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "net/cert/cert_verify_proc_builtin.h"
 #include "net/cert/internal/system_trust_store.h"
 #endif
@@ -89,7 +89,7 @@ class OldDefaultCertVerifyProcFactory : public net::Ce
             user_slot_restriction_ ? crypto::ScopedPK11Slot(PK11_ReferenceSlot(
                                          user_slot_restriction_.get()))
                                    : nullptr));
-#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     verify_proc = net::CreateCertVerifyProcBuiltin(
         std::move(cert_net_fetcher), net::CreateSslSystemTrustStore());
 #else
@@ -212,6 +212,7 @@ std::unique_ptr<net::CertVerifierWithUpdatableProc> Cr
 bool IsUsingCertNetFetcher() {
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) ||      \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||       \
+    BUILDFLAG(IS_BSD) ||                                   \
     BUILDFLAG(TRIAL_COMPARISON_CERT_VERIFIER_SUPPORTED) || \
     BUILDFLAG(CHROME_ROOT_STORE_SUPPORTED)
   return true;
