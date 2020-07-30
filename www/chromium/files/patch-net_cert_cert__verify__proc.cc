--- net/cert/cert_verify_proc.cc.orig	2020-07-07 21:58:16 UTC
+++ net/cert/cert_verify_proc.cc
@@ -494,7 +494,7 @@ base::Value CertVerifyParams(X509Certificate* cert,
 
 }  // namespace
 
-#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 // static
 scoped_refptr<CertVerifyProc> CertVerifyProc::CreateSystemVerifyProc(
     scoped_refptr<CertNetFetcher> cert_net_fetcher) {
