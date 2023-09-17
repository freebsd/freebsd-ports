--- chrome/browser/ui/webauthn/sheet_models.cc.orig	2023-09-17 07:59:53 UTC
+++ chrome/browser/ui/webauthn/sheet_models.cc
@@ -1496,7 +1496,11 @@ AuthenticatorMultiSourcePickerSheetModel::
 
   using CredentialMech = AuthenticatorRequestDialogModel::Mechanism::Credential;
   bool has_local_passkeys =
+#if (_LIBCPP_VERSION >= 160000)
       std::ranges::any_of(dialog_model->mechanisms(), [](const auto& mech) {
+#else
+      base::ranges::any_of(dialog_model->mechanisms(), [](const auto& mech) {
+#endif
         return absl::holds_alternative<CredentialMech>(mech.type) &&
                absl::get<CredentialMech>(mech.type).value() !=
                    device::AuthenticatorType::kPhone;
