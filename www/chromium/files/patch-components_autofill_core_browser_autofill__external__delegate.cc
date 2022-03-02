--- components/autofill/core/browser/autofill_external_delegate.cc.orig	2022-02-28 16:54:41 UTC
+++ components/autofill/core/browser/autofill_external_delegate.cc
@@ -130,7 +130,7 @@ void AutofillExternalDelegate::OnSuggestionsReturned(
     // Append the "Hide Suggestions" menu item for only Autofill Address and
     // Autocomplete popups.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kAutofillEnableHideSuggestionsUI)) {
     // If the user has selected a suggestion, it indicates the suggestions are
