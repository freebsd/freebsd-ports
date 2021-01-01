--- net/base/features.cc.orig	2020-03-17 10:02:15 UTC
+++ net/base/features.cc
@@ -88,7 +88,7 @@ const base::FeatureParam<int>
 #if BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
 const base::Feature kCertVerifierBuiltinFeature {
   "CertVerifierBuiltin",
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
