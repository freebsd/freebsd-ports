--- components/password_manager/core/browser/ui/passwords_grouper.cc.orig	2023-08-17 12:40:56 UTC
+++ components/password_manager/core/browser/ui/passwords_grouper.cc
@@ -399,6 +399,7 @@ absl::optional<PasskeyCredential> PasswordsGrouper::Ge
   if (group_id_iterator == map_signon_realm_to_group_id_.end()) {
     return absl::nullopt;
   }
+#if BUILDFLAG(IS_OPENBSD) || (BUILDFLAG(IS_FREEBSD) && (_LIBCPP_VERSION > 15000))
   // Find the passkey in the group.
   const std::vector<PasskeyCredential>& passkeys =
       map_group_id_to_credentials_[group_id_iterator->second].passkeys;
@@ -410,6 +411,10 @@ absl::optional<PasskeyCredential> PasswordsGrouper::Ge
     return absl::nullopt;
   }
   return *passkey_it;
+#else
+  LOG(ERROR) << "Unable to lookup in password group";
+  return absl::nullopt;
+#endif
 }
 
 void PasswordsGrouper::ClearCache() {
