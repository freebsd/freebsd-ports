--- chrome/browser/webauthn/enclave_manager.cc.orig	2025-02-20 09:59:21 UTC
+++ chrome/browser/webauthn/enclave_manager.cc
@@ -686,7 +686,7 @@ base::flat_set<GaiaId> GetGaiaIDs(
 
 std::string UserVerifyingLabelToString(crypto::UserVerifyingKeyLabel label) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   return label;
 #else
   return std::string("placeholder");
@@ -696,7 +696,7 @@ std::string UserVerifyingLabelToString(crypto::UserVer
 std::optional<crypto::UserVerifyingKeyLabel> UserVerifyingKeyLabelFromString(
     std::string saved_label) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   return saved_label;
 #else
   return std::nullopt;
