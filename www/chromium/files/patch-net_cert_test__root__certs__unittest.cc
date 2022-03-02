--- net/cert/test_root_certs_unittest.cc.orig	2022-02-28 16:54:41 UTC
+++ net/cert/test_root_certs_unittest.cc
@@ -33,7 +33,7 @@ const char kRootCertificateFile[] = "root_ca_cert.pem"
 const char kGoodCertificateFile[] = "ok_cert.pem";
 
 scoped_refptr<CertVerifyProc> CreateCertVerifyProc() {
-#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return CertVerifyProc::CreateBuiltinVerifyProc(/*cert_net_fetcher=*/nullptr);
 #elif BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
   if (base::FeatureList::IsEnabled(features::kCertVerifierBuiltinFeature)) {
