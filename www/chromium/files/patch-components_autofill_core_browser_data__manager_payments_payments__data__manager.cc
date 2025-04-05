--- components/autofill/core/browser/data_manager/payments/payments_data_manager.cc.orig	2025-04-04 08:52:13 UTC
+++ components/autofill/core/browser/data_manager/payments/payments_data_manager.cc
@@ -1003,7 +1003,7 @@ void PaymentsDataManager::SetAutofillHasSeenIban() {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool PaymentsDataManager::IsAutofillHasSeenBnplPrefEnabled() const {
   return prefs::HasSeenBnpl(pref_service_);
 }
@@ -1172,7 +1172,7 @@ bool PaymentsDataManager::IsServerCard(const CreditCar
 bool PaymentsDataManager::ShouldShowCardsFromAccountOption() const {
 // The feature is only for Linux, Windows, Mac, and Fuchsia.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // This option should only be shown for users that have not enabled the Sync
   // Feature and that have server credit cards available.
   // TODO(crbug.com/40066949): Simplify once ConsentLevel::kSync and
@@ -2026,7 +2026,7 @@ bool PaymentsDataManager::AreEwalletAccountsSupported(
 
 bool PaymentsDataManager::AreBnplIssuersSupported() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return app_locale_ == "en-US" &&
          base::FeatureList::IsEnabled(
              features::kAutofillEnableBuyNowPayLaterSyncing);
