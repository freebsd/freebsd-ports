--- src/3rdparty/chromium/net/cert/cert_verify_proc.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/net/cert/cert_verify_proc.h
@@ -66,7 +66,7 @@ class NET_EXPORT CertVerifyProc
     kMaxValue = kChainLengthOne
   };
 
-#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   // Creates and returns a CertVerifyProc that uses the system verifier.
   // |cert_net_fetcher| may not be used, depending on the implementation.
   static scoped_refptr<CertVerifyProc> CreateSystemVerifyProc(
