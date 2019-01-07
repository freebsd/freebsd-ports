--- components/autofill/core/browser/autofill_experiments.cc.orig	2018-12-12 22:56:05.000000000 +0100
+++ components/autofill/core/browser/autofill_experiments.cc	2018-12-28 16:48:40.407244000 +0100
@@ -27,7 +27,7 @@
 
 namespace autofill {
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 namespace {
 // Returns the font weight corresponding to the value of param
 // kAutofillForcedFontWeightParameterName, or kDefault if the param is not
@@ -45,9 +45,9 @@
   return ForcedFontWeight::kDefault;
 }
 }  // namespace
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 const base::Feature kAutofillDropdownLayoutExperiment{
     "AutofillDropdownLayout", base::FEATURE_DISABLED_BY_DEFAULT};
 const char kAutofillDropdownLayoutParameterName[] = "variant";
@@ -55,15 +55,15 @@
 const char kAutofillDropdownLayoutParameterTrailingIcon[] = "trailing-icon";
 const char kAutofillDropdownLayoutParameterTwoLinesLeadingIcon[] =
     "two-lines-leading-icon";
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 const base::Feature kAutofillPrimaryInfoStyleExperiment{
     "AutofillPrimaryInfoStyleExperiment", base::FEATURE_DISABLED_BY_DEFAULT};
 const char kAutofillForcedFontWeightParameterName[] = "font_weight";
 const char kAutofillForcedFontWeightParameterMedium[] = "medium";
 const char kAutofillForcedFontWeightParameterBold[] = "bold";
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 bool IsCreditCardUploadEnabled(const PrefService* pref_service,
                                const syncer::SyncService* sync_service,
@@ -152,7 +152,7 @@
 }
 
 bool OfferStoreUnmaskedCards() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   // The checkbox can be forced on with a flag, but by default we don't store
   // on Linux due to lack of system keychain integration. See crbug.com/162735
   return base::CommandLine::ForCurrentProcess()->HasSwitch(
@@ -185,7 +185,7 @@
              features::kAutofillGetPaymentsIdentityFromSync);
 }
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 ForcedFontWeight GetForcedFontWeight() {
   if (!base::FeatureList::IsEnabled(kAutofillPrimaryInfoStyleExperiment))
     return ForcedFontWeight::kDefault;
@@ -194,9 +194,9 @@
   static ForcedFontWeight font_weight_from_param = GetFontWeightFromParam();
   return font_weight_from_param;
 }
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 ForcedPopupLayoutState GetForcedPopupLayoutState() {
   if (!base::FeatureList::IsEnabled(
           autofill::kAutofillDropdownLayoutExperiment))
@@ -220,6 +220,6 @@
   NOTREACHED();
   return ForcedPopupLayoutState::kDefault;
 }
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 }  // namespace autofill
