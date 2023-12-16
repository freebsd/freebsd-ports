--- components/autofill/core/browser/payments/iban_save_manager.cc.orig	2023-11-22 14:00:11 UTC
+++ components/autofill/core/browser/payments/iban_save_manager.cc
@@ -63,7 +63,11 @@ bool IbanSaveManager::AttemptToOfferIbanLocalSave(
 bool IbanSaveManager::ShouldOfferLocalSave(const Iban& iban_import_candidate) {
   // Only offer to save new IBANs. Users can go to the payment methods settings
   // page to update existing IBANs if desired.
+#if (_LIBCPP_VERSION >= 160000)
   return std::ranges::none_of(
+#else
+  return base::ranges::none_of(
+#endif
       personal_data_manager_->GetLocalIbans(), [&](const auto& iban) {
         return iban->value() == iban_import_candidate.value();
       });
