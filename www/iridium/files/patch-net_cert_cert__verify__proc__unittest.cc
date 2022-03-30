--- net/cert/cert_verify_proc_unittest.cc.orig	2022-03-28 18:11:04 UTC
+++ net/cert/cert_verify_proc_unittest.cc
@@ -223,7 +223,7 @@ const std::vector<CertVerifyProcType> kAllCertVerifier
     CERT_VERIFY_PROC_MAC, CERT_VERIFY_PROC_BUILTIN
 #elif BUILDFLAG(IS_WIN)
     CERT_VERIFY_PROC_WIN
-#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     CERT_VERIFY_PROC_BUILTIN
 #else
 #error Unsupported platform
