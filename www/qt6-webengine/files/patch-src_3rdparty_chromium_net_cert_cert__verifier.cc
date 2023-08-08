--- src/3rdparty/chromium/net/cert/cert_verifier.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/net/cert/cert_verifier.cc
@@ -87,7 +87,7 @@ std::unique_ptr<CertVerifier> CertVerifier::CreateDefa
   }
 #endif
   if (!verify_proc) {
-#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     verify_proc =
         CertVerifyProc::CreateBuiltinVerifyProc(std::move(cert_net_fetcher));
 #else
