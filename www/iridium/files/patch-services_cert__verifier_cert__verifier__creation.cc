--- services/cert_verifier/cert_verifier_creation.cc.orig	2023-11-22 14:00:11 UTC
+++ services/cert_verifier/cert_verifier_creation.cc
@@ -13,7 +13,7 @@
 #include "net/cert/multi_threaded_cert_verifier.h"
 #include "net/net_buildflags.h"
 
-#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "net/cert/cert_verify_proc_builtin.h"
 #include "net/cert/internal/system_trust_store.h"
 #endif
@@ -108,7 +108,7 @@ class CertVerifyProcFactoryImpl : public net::CertVeri
             user_slot_restriction_ ? crypto::ScopedPK11Slot(PK11_ReferenceSlot(
                                          user_slot_restriction_.get()))
                                    : nullptr));
-#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return net::CreateCertVerifyProcBuiltin(std::move(cert_net_fetcher),
                                             std::move(crl_set),
                                             net::CreateSslSystemTrustStore());
@@ -174,6 +174,7 @@ class CertVerifyProcFactoryImpl : public net::CertVeri
 bool IsUsingCertNetFetcher() {
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) ||      \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||       \
+    BUILDFLAG(IS_BSD) ||                                   \
     BUILDFLAG(CHROME_ROOT_STORE_SUPPORTED)
   return true;
 #else
