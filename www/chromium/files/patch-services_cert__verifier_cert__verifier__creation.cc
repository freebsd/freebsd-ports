--- services/cert_verifier/cert_verifier_creation.cc.orig	2021-09-24 18:55:25 UTC
+++ services/cert_verifier/cert_verifier_creation.cc
@@ -86,7 +86,7 @@ scoped_refptr<net::CertVerifyProc> CreateCertVerifyPro
 scoped_refptr<net::CertVerifyProc> CreateOldDefaultWithoutCaching(
     scoped_refptr<net::CertNetFetcher> cert_net_fetcher) {
   scoped_refptr<net::CertVerifyProc> verify_proc;
-#if defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   verify_proc =
       net::CertVerifyProc::CreateBuiltinVerifyProc(std::move(cert_net_fetcher));
 #else
@@ -103,7 +103,7 @@ scoped_refptr<net::CertVerifyProc> CreateOldDefaultWit
 scoped_refptr<net::CertVerifyProc> CreateNewDefaultWithoutCaching(
     scoped_refptr<net::CertNetFetcher> cert_net_fetcher) {
   scoped_refptr<net::CertVerifyProc> verify_proc;
-#if BUILDFLAG(CHROME_ROOT_STORE_SUPPORTED) && defined(OS_LINUX)
+#if BUILDFLAG(CHROME_ROOT_STORE_SUPPORTED) && (defined(OS_LINUX) || defined(OS_BSD))
   verify_proc = net::CreateCertVerifyProcBuiltin(
       std::move(cert_net_fetcher), net::CreateSslSystemTrustStoreChromeRoot());
 #elif BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
