--- chrome/browser/ui/webauthn/sheet_models.cc.orig	2023-10-13 13:20:35 UTC
+++ chrome/browser/ui/webauthn/sheet_models.cc
@@ -1499,7 +1499,11 @@ AuthenticatorMultiSourcePickerSheetModel::
   using ICloudKeychainMech =
       AuthenticatorRequestDialogModel::Mechanism::ICloudKeychain;
   bool has_local_passkeys =
+#if (_LIBCPP_VERSION >= 160000)
       std::ranges::any_of(dialog_model->mechanisms(), [](const auto& mech) {
+#else
+      base::ranges::any_of(dialog_model->mechanisms(), [](const auto& mech) {
+#endif
         return absl::holds_alternative<CredentialMech>(mech.type) &&
                absl::get<CredentialMech>(mech.type).value().source !=
                    device::AuthenticatorType::kPhone;
