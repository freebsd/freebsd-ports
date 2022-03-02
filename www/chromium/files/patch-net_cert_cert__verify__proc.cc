--- net/cert/cert_verify_proc.cc.orig	2022-02-28 16:54:41 UTC
+++ net/cert/cert_verify_proc.cc
@@ -470,7 +470,7 @@ base::Value CertVerifyParams(X509Certificate* cert,
 
 }  // namespace
 
-#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // static
 scoped_refptr<CertVerifyProc> CertVerifyProc::CreateSystemVerifyProc(
     scoped_refptr<CertNetFetcher> cert_net_fetcher) {
