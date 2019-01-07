--- components/autofill/core/browser/autofill_experiments.h.orig	2018-12-28 16:46:01.899706000 +0100
+++ components/autofill/core/browser/autofill_experiments.h	2018-12-28 16:46:45.873415000 +0100
@@ -23,20 +23,20 @@
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
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 extern const base::Feature kAutofillPrimaryInfoStyleExperiment;
 extern const char kAutofillForcedFontWeightParameterName[];
 extern const char kAutofillForcedFontWeightParameterMedium[];
 extern const char kAutofillForcedFontWeightParameterBold[];
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 // Returns true if uploading credit cards to Wallet servers is enabled. This
 // requires the appropriate flags and user settings to be true and the user to
@@ -66,7 +66,7 @@
 // Returns whether the account of the active signed-in user should be used.
 bool ShouldUseActiveSignedInAccount();
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 enum class ForcedFontWeight {
   kDefault,  // No change to the font weight.
   kMedium,
@@ -78,9 +78,9 @@
 // kAutofillPrimaryInfoStyleExperiment is disabled or if the corresponding
 // feature param is invalid.
 ForcedFontWeight GetForcedFontWeight();
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 enum class ForcedPopupLayoutState {
   kDefault,       // No popup layout forced by experiment.
   kLeadingIcon,   // Experiment forces leading (left in LTR) icon layout.
@@ -94,7 +94,7 @@
 // if the experiment param matches kAutofillDropdownLayoutParameterLeadingIcon
 // or kAutofillDropdownLayoutParameterTrailingIcon, respectively.
 ForcedPopupLayoutState GetForcedPopupLayoutState();
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 }  // namespace autofill
 
