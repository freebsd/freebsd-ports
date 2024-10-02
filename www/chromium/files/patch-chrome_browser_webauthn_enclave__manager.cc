--- chrome/browser/webauthn/enclave_manager.cc.orig	2024-09-30 07:45:04 UTC
+++ chrome/browser/webauthn/enclave_manager.cc
@@ -693,7 +693,7 @@ base::flat_set<std::string> GetGaiaIDs(
 
 std::string UserVerifyingLabelToString(crypto::UserVerifyingKeyLabel label) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   return label;
 #else
   return std::string("placeholder");
@@ -703,7 +703,7 @@ std::string UserVerifyingLabelToString(crypto::UserVer
 std::optional<crypto::UserVerifyingKeyLabel> UserVerifyingKeyLabelFromString(
     std::string saved_label) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   return saved_label;
 #else
   return std::nullopt;
