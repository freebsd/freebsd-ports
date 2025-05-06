--- components/autofill/core/browser/data_manager/payments/payments_data_manager.cc.orig	2025-05-05 10:57:53 UTC
+++ components/autofill/core/browser/data_manager/payments/payments_data_manager.cc
@@ -950,7 +950,7 @@ void PaymentsDataManager::SetPrefService(PrefService* 
           &PaymentsDataManager::OnAutofillPaymentsCardBenefitsPrefChange,
           base::Unretained(this)));
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   pref_registrar_.Add(
       prefs::kAutofillBnplEnabled,
       base::BindRepeating(&PaymentsDataManager::OnBnplEnabledPrefChange,
@@ -1026,7 +1026,7 @@ void PaymentsDataManager::SetAutofillHasSeenIban() {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool PaymentsDataManager::IsAutofillHasSeenBnplPrefEnabled() const {
   return prefs::HasSeenBnpl(pref_service_);
 }
@@ -2022,7 +2022,7 @@ bool PaymentsDataManager::AreEwalletAccountsSupported(
 
 bool PaymentsDataManager::AreBnplIssuersSupported() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return app_locale_ == "en-US" && GetCountryCodeForExperimentGroup() == "US" &&
          base::FeatureList::IsEnabled(
              features::kAutofillEnableBuyNowPayLaterSyncing);
@@ -2055,7 +2055,7 @@ void PaymentsDataManager::ClearAllCreditCardBenefits()
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void PaymentsDataManager::OnBnplEnabledPrefChange() {
   // On pref change to `false`, clearing BNPL issuers is implicitly handled by
   // `GetBnplIssuers()`, since it returns an empty vector when
