--- components/autofill/core/browser/autofill_experiments.cc.orig	2019-03-11 22:00:56 UTC
+++ components/autofill/core/browser/autofill_experiments.cc
@@ -28,7 +28,7 @@
 
 namespace autofill {
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 const base::Feature kAutofillDropdownLayoutExperiment{
     "AutofillDropdownLayout", base::FEATURE_DISABLED_BY_DEFAULT};
 const char kAutofillDropdownLayoutParameterName[] = "variant";
@@ -36,7 +36,7 @@ const char kAutofillDropdownLayoutParameterLeadingIcon
 const char kAutofillDropdownLayoutParameterTrailingIcon[] = "trailing-icon";
 const char kAutofillDropdownLayoutParameterTwoLinesLeadingIcon[] =
     "two-lines-leading-icon";
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 bool IsCreditCardUploadEnabled(const PrefService* pref_service,
                                const syncer::SyncService* sync_service,
@@ -143,7 +143,7 @@ bool IsAutofillNoLocalSaveOnUploadSuccessExperimentEna
 }
 
 bool OfferStoreUnmaskedCards(bool is_off_the_record) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // The checkbox can be forced on with a flag, but by default we don't store
   // on Linux due to lack of system keychain integration. See crbug.com/162735
   return base::CommandLine::ForCurrentProcess()->HasSwitch(
@@ -181,7 +181,7 @@ bool ShouldUseActiveSignedInAccount() {
              features::kAutofillGetPaymentsIdentityFromSync);
 }
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 ForcedPopupLayoutState GetForcedPopupLayoutState() {
   if (!base::FeatureList::IsEnabled(
           autofill::kAutofillDropdownLayoutExperiment))
@@ -205,6 +205,6 @@ ForcedPopupLayoutState GetForcedPopupLayoutState() {
   NOTREACHED();
   return ForcedPopupLayoutState::kDefault;
 }
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 }  // namespace autofill
