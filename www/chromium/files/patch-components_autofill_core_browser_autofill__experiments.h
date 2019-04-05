--- components/autofill/core/browser/autofill_experiments.h.orig	2019-03-11 22:00:56 UTC
+++ components/autofill/core/browser/autofill_experiments.h
@@ -23,13 +23,13 @@ class SyncService;
 namespace autofill {
 
 // Parameterized Features (grouped with parameter name and options)
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 extern const base::Feature kAutofillDropdownLayoutExperiment;
 extern const char kAutofillDropdownLayoutParameterName[];
 extern const char kAutofillDropdownLayoutParameterLeadingIcon[];
 extern const char kAutofillDropdownLayoutParameterTrailingIcon[];
 extern const char kAutofillDropdownLayoutParameterTwoLinesLeadingIcon[];
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 // Returns true if uploading credit cards to Wallet servers is enabled. This
 // requires the appropriate flags and user settings to be true and the user to
@@ -59,7 +59,7 @@ bool OfferStoreUnmaskedCards(bool is_off_the_record);
 // Returns whether the account of the active signed-in user should be used.
 bool ShouldUseActiveSignedInAccount();
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 enum class ForcedPopupLayoutState {
   kDefault,       // No popup layout forced by experiment.
   kLeadingIcon,   // Experiment forces leading (left in LTR) icon layout.
@@ -73,7 +73,7 @@ enum class ForcedPopupLayoutState {
 // if the experiment param matches kAutofillDropdownLayoutParameterLeadingIcon
 // or kAutofillDropdownLayoutParameterTrailingIcon, respectively.
 ForcedPopupLayoutState GetForcedPopupLayoutState();
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 }  // namespace autofill
 
