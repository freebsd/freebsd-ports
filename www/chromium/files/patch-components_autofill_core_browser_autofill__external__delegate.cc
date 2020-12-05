--- components/autofill/core/browser/autofill_external_delegate.cc.orig	2020-11-13 06:36:40 UTC
+++ components/autofill/core/browser/autofill_external_delegate.cc
@@ -127,7 +127,7 @@ void AutofillExternalDelegate::OnSuggestionsReturned(
 
     // Append the "Hide Suggestions" menu item for only Autofill Address and
     // Autocomplete popups.
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_APPLE) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_APPLE) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   if (base::FeatureList::IsEnabled(
           features::kAutofillEnableHideSuggestionsUI)) {
