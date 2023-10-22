--- net/cert/cert_verify_proc_unittest.cc.orig	2023-11-22 14:00:11 UTC
+++ net/cert/cert_verify_proc_unittest.cc
@@ -213,7 +213,7 @@ scoped_refptr<CertVerifyProc> CreateCertVerifyProc(
     case CERT_VERIFY_PROC_IOS:
       return base::MakeRefCounted<CertVerifyProcIOS>(std::move(crl_set));
 #endif
-#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case CERT_VERIFY_PROC_BUILTIN:
       return CreateCertVerifyProcBuiltin(std::move(cert_net_fetcher),
                                          std::move(crl_set),
@@ -242,7 +242,7 @@ constexpr CertVerifyProcType kAllCertVerifiers[] = {
     CERT_VERIFY_PROC_ANDROID,
 #elif BUILDFLAG(IS_IOS)
     CERT_VERIFY_PROC_IOS,
-#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     CERT_VERIFY_PROC_BUILTIN,
 #endif
 #if BUILDFLAG(CHROME_ROOT_STORE_SUPPORTED)
