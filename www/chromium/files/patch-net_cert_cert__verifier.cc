--- net/cert/cert_verifier.cc.orig	2021-07-19 18:45:19 UTC
+++ net/cert/cert_verifier.cc
@@ -78,7 +78,7 @@ bool CertVerifier::RequestParams::operator<(
 std::unique_ptr<CertVerifier> CertVerifier::CreateDefaultWithoutCaching(
     scoped_refptr<CertNetFetcher> cert_net_fetcher) {
   scoped_refptr<CertVerifyProc> verify_proc;
-#if defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   verify_proc =
       CertVerifyProc::CreateBuiltinVerifyProc(std::move(cert_net_fetcher));
 #elif BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
