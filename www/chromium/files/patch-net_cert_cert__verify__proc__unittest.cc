--- net/cert/cert_verify_proc_unittest.cc.orig	2022-08-31 12:19:35 UTC
+++ net/cert/cert_verify_proc_unittest.cc
@@ -234,7 +234,7 @@ const std::vector<CertVerifyProcType> kAllCertVerifier
     CERT_VERIFY_PROC_BUILTIN_CHROME_ROOTS
 #elif BUILDFLAG(IS_WIN)
     CERT_VERIFY_PROC_WIN, CERT_VERIFY_PROC_BUILTIN_CHROME_ROOTS
-#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     CERT_VERIFY_PROC_BUILTIN
 #else
 #error Unsupported platform
