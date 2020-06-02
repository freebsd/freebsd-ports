--- net/base/features.cc.orig	2020-05-13 18:40:32 UTC
+++ net/base/features.cc
@@ -92,7 +92,7 @@ const base::Feature kBlockExternalRequestsFromNonSecur
 #if BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
 const base::Feature kCertVerifierBuiltinFeature {
   "CertVerifierBuiltin",
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
