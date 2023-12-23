--- components/autofill/core/browser/data_model/autofill_i18n_api.h.orig	2023-12-23 12:33:28 UTC
+++ components/autofill/core/browser/data_model/autofill_i18n_api.h
@@ -15,9 +15,13 @@ namespace autofill::i18n_model_definition {
 // Country code that represents autofill's legacy address hierarchy model as
 // stored `kAutofillModelRules`. As a workaround for GCC we declare the
 // std::string constexpr first.
+// XXX
+#if 0
 constexpr inline std::string kLegacyHierarchyCountryCodeString{"XX"};
 constexpr AddressCountryCode kLegacyHierarchyCountryCode =
     AddressCountryCode(kLegacyHierarchyCountryCodeString);
+#endif
+inline AddressCountryCode kLegacyHierarchyCountryCode = AddressCountryCode("XX");
 
 // Creates an instance of the address hierarchy model corresponding to the
 // provided country. All the nodes have empty values, except for the country
