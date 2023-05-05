--- net/cert/cert_verifier.cc.orig	2023-05-05 12:12:41 UTC
+++ net/cert/cert_verifier.cc
@@ -91,7 +91,7 @@ std::unique_ptr<CertVerifier> CertVerifier::CreateDefa
 #if BUILDFLAG(CHROME_ROOT_STORE_ONLY)
     verify_proc = CertVerifyProc::CreateBuiltinWithChromeRootStore(
         std::move(cert_net_fetcher));
-#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     verify_proc =
         CertVerifyProc::CreateBuiltinVerifyProc(std::move(cert_net_fetcher));
 #else
