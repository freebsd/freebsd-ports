--- net/cert/test_root_certs_unittest.cc.orig	2023-05-05 12:12:41 UTC
+++ net/cert/test_root_certs_unittest.cc
@@ -43,7 +43,7 @@ scoped_refptr<CertVerifyProc> CreateCertVerifyProc() {
 #if BUILDFLAG(CHROME_ROOT_STORE_ONLY)
   return CertVerifyProc::CreateBuiltinWithChromeRootStore(
       /*cert_net_fetcher=*/nullptr);
-#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return CertVerifyProc::CreateBuiltinVerifyProc(/*cert_net_fetcher=*/nullptr);
 #else
   return CertVerifyProc::CreateSystemVerifyProc(/*cert_net_fetcher=*/nullptr);
