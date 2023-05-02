--- net/cert/cert_verify_proc_unittest.cc.orig	2023-04-28 17:01:32 UTC
+++ net/cert/cert_verify_proc_unittest.cc
@@ -222,7 +222,7 @@ scoped_refptr<CertVerifyProc> CreateCertVerifyProc(
     case CERT_VERIFY_PROC_WIN:
       return base::MakeRefCounted<CertVerifyProcWin>();
 #endif
-#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case CERT_VERIFY_PROC_BUILTIN:
       return CreateCertVerifyProcBuiltin(std::move(cert_net_fetcher),
                                          CreateSslSystemTrustStore());
@@ -252,7 +252,7 @@ constexpr CertVerifyProcType kAllCertVerifiers[] = {
     CERT_VERIFY_PROC_IOS,
 #elif BUILDFLAG(IS_WIN)
     CERT_VERIFY_PROC_WIN,
-#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     CERT_VERIFY_PROC_BUILTIN,
 #endif
 #if BUILDFLAG(CHROME_ROOT_STORE_SUPPORTED)
