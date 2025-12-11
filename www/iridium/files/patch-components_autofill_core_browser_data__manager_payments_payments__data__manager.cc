--- components/autofill/core/browser/data_manager/payments/payments_data_manager.cc.orig	2025-12-10 15:04:57 UTC
+++ components/autofill/core/browser/data_manager/payments/payments_data_manager.cc
@@ -480,7 +480,7 @@ void PaymentsDataManager::OnWebDataServiceRequestDone(
 
 bool PaymentsDataManager::ShouldShowBnplSettings() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Check `kAutofillEnableBuyNowPayLater` only if the user has seen a BNPL
   // suggestion before, or there are already linked issuers present, to avoid
   // unnecessary feature flag checks. The linked issuer check is due to the fact
@@ -1015,7 +1015,7 @@ void PaymentsDataManager::SetPrefService(PrefService* 
           &PaymentsDataManager::OnAutofillPaymentsCardBenefitsPrefChange,
           base::Unretained(this)));
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   pref_registrar_.Add(
       prefs::kAutofillBnplEnabled,
       base::BindRepeating(&PaymentsDataManager::OnBnplEnabledPrefChange,
@@ -1089,7 +1089,7 @@ void PaymentsDataManager::SetAutofillHasSeenIban() {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 bool PaymentsDataManager::IsAutofillHasSeenBnplPrefEnabled() const {
   return prefs::HasSeenBnpl(pref_service_);
 }
@@ -2140,7 +2140,7 @@ bool PaymentsDataManager::AreEwalletAccountsSupported(
 
 bool PaymentsDataManager::AreBnplIssuersSupported() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return (app_locale_ == "en-US" || app_locale_ == "en-GB" ||
           app_locale_ == "en-CA") &&
          GetCountryCodeForExperimentGroup() == "US" &&
@@ -2175,7 +2175,7 @@ void PaymentsDataManager::ClearAllCreditCardBenefits()
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void PaymentsDataManager::OnBnplEnabledPrefChange() {
   // On pref change to `false`, clearing BNPL issuers is implicitly handled by
   // `GetBnplIssuers()`, since it returns an empty vector when
