--- net/cert/cert_verifier.cc.orig	2020-11-13 06:36:45 UTC
+++ net/cert/cert_verifier.cc
@@ -87,7 +87,7 @@ std::unique_ptr<CertVerifier> CertVerifier::CreateDefa
   return std::unique_ptr<CertVerifier>();
 #else
   scoped_refptr<CertVerifyProc> verify_proc;
-#if defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   verify_proc =
       CertVerifyProc::CreateBuiltinVerifyProc(std::move(cert_net_fetcher));
 #elif BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
