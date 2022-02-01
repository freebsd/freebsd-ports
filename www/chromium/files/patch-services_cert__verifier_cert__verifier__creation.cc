--- services/cert_verifier/cert_verifier_creation.cc.orig	2021-12-14 11:45:09 UTC
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
@@ -104,7 +104,7 @@ scoped_refptr<net::CertVerifyProc> CreateNewDefaultWit
     scoped_refptr<net::CertNetFetcher> cert_net_fetcher) {
   scoped_refptr<net::CertVerifyProc> verify_proc;
 #if BUILDFLAG(CHROME_ROOT_STORE_SUPPORTED) && \
-    (defined(OS_LINUX) || defined(OS_WIN))
+    (defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD))
   verify_proc = net::CreateCertVerifyProcBuiltin(
       std::move(cert_net_fetcher), net::CreateSslSystemTrustStoreChromeRoot());
 #elif BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
@@ -120,7 +120,7 @@ scoped_refptr<net::CertVerifyProc> CreateNewDefaultWit
 
 bool IsUsingCertNetFetcher() {
 #if defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_CHROMEOS) || \
-    defined(OS_LINUX) ||                                                  \
+    defined(OS_LINUX) || defined(OS_BSD) ||                               \
     BUILDFLAG(TRIAL_COMPARISON_CERT_VERIFIER_SUPPORTED) ||                \
     BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
   return true;
