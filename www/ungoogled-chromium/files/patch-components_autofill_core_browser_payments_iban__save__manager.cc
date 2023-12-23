--- components/autofill/core/browser/payments/iban_save_manager.cc.orig	2023-12-23 12:33:28 UTC
+++ components/autofill/core/browser/payments/iban_save_manager.cc
@@ -123,7 +123,11 @@ bool IbanSaveManager::ShouldOfferUploadSave(
 
   // Offer server save for this IBAN if it doesn't already match an existing
   // server IBAN.
+#if (_LIBCPP_VERSION >= 160000)
   return std::ranges::none_of(
+#else
+  return base::ranges::none_of(
+#endif
       personal_data_manager_->GetServerIbans(),
       [&iban_import_candidate](const auto& iban) {
         return iban->MatchesPrefixSuffixAndLength(iban_import_candidate);
