--- chrome/browser/webauthn/enclave_manager.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/webauthn/enclave_manager.cc
@@ -743,7 +743,7 @@ base::flat_set<GaiaId> GetGaiaIDs(
 
 std::string UserVerifyingLabelToString(crypto::UserVerifyingKeyLabel label) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return label;
 #else
   return std::string("placeholder");
@@ -753,7 +753,7 @@ std::string UserVerifyingLabelToString(crypto::UserVer
 std::optional<crypto::UserVerifyingKeyLabel> UserVerifyingKeyLabelFromString(
     std::string saved_label) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return saved_label;
 #else
   return std::nullopt;
