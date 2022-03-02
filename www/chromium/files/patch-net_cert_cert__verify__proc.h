--- net/cert/cert_verify_proc.h.orig	2022-02-28 16:54:41 UTC
+++ net/cert/cert_verify_proc.h
@@ -66,7 +66,7 @@ class NET_EXPORT CertVerifyProc
     kMaxValue = kChainLengthOne
   };
 
-#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
   // Creates and returns a CertVerifyProc that uses the system verifier.
   // |cert_net_fetcher| may not be used, depending on the implementation.
   static scoped_refptr<CertVerifyProc> CreateSystemVerifyProc(
