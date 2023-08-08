--- src/3rdparty/chromium/services/network/public/cpp/cert_verifier/cert_verifier_creation.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/services/network/public/cpp/cert_verifier/cert_verifier_creation.cc
@@ -70,7 +70,7 @@ bool IsUsingCertNetFetcher() {
 
 bool IsUsingCertNetFetcher() {
 #if defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_CHROMEOS) || \
-    defined(OS_LINUX) ||                                                  \
+    defined(OS_LINUX) || defined(OS_BSD) ||                               \
     BUILDFLAG(TRIAL_COMPARISON_CERT_VERIFIER_SUPPORTED) ||                \
     BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
   return true;
