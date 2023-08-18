--- components/webauthn/core/browser/passkey_sync_bridge.cc.orig	2023-08-18 10:26:52 UTC
+++ components/webauthn/core/browser/passkey_sync_bridge.cc
@@ -267,6 +267,7 @@ PasskeySyncBridge::GetAllPasskeys() const {
 
 bool PasskeySyncBridge::DeletePasskey(const std::string& credential_id) {
   // Find the credential with the given |credential_id|.
+#if BUILDFLAG(IS_OPENBSD) || (BUILDFLAG(IS_FREEBSD) && (_LIBCPP_VERSION > 15000))
   const auto passkey_it =
       std::ranges::find_if(data_, [&credential_id](const auto& passkey) {
         return passkey.second.credential_id() == credential_id;
@@ -313,11 +314,16 @@ bool PasskeySyncBridge::DeletePasskey(const std::strin
                      weak_ptr_factory_.GetWeakPtr()));
   NotifyPasskeysChanged();
   return true;
+#else
+  LOG(ERROR) << "Unable to delete passkey"; 
+  return false;
+#endif
 }
 
 bool PasskeySyncBridge::UpdatePasskey(const std::string& credential_id,
                                       PasskeyChange change) {
   // Find the credential with the given |credential_id|.
+#if BUILDFLAG(IS_OPENBSD) || (BUILDFLAG(IS_FREEBSD) && (_LIBCPP_VERSION > 15000))
   const auto passkey_it =
       std::ranges::find_if(data_, [&credential_id](const auto& passkey) {
         return passkey.second.credential_id() == credential_id;
@@ -341,6 +347,10 @@ bool PasskeySyncBridge::UpdatePasskey(const std::strin
                      weak_ptr_factory_.GetWeakPtr()));
   NotifyPasskeysChanged();
   return true;
+#else
+  LOG(ERROR) << "Unable to update passkey"; 
+  return false;
+#endif
 }
 
 std::string PasskeySyncBridge::AddNewPasskeyForTesting(
