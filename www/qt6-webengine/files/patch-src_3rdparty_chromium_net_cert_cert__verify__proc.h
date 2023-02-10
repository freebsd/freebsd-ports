--- src/3rdparty/chromium/net/cert/cert_verify_proc.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/net/cert/cert_verify_proc.h
@@ -79,7 +79,7 @@ class NET_EXPORT CertVerifyProc
     kMaxValue = kOther
   };
 
-#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
   // Creates and returns a CertVerifyProc that uses the system verifier.
   // |cert_net_fetcher| may not be used, depending on the implementation.
   static scoped_refptr<CertVerifyProc> CreateSystemVerifyProc(
