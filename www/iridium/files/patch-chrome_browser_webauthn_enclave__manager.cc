--- chrome/browser/webauthn/enclave_manager.cc.orig	2024-06-25 12:08:48 UTC
+++ chrome/browser/webauthn/enclave_manager.cc
@@ -652,7 +652,7 @@ base::flat_set<std::string> GetGaiaIDs(
 }
 
 std::string UserVerifyingLabelToString(crypto::UserVerifyingKeyLabel label) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return label;
 #else
   return std::string("placeholder");
@@ -661,7 +661,7 @@ std::string UserVerifyingLabelToString(crypto::UserVer
 
 std::optional<crypto::UserVerifyingKeyLabel> UserVerifyingKeyLabelFromString(
     std::string saved_label) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return saved_label;
 #else
   return std::nullopt;
