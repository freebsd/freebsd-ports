--- chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc
@@ -89,7 +89,7 @@ ChromeAutocompleteSchemeClassifier::GetInputTypeForSch
       return metrics::OmniboxInputType::QUERY;
 
     case ExternalProtocolHandler::UNKNOWN: {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // Linux impl of GetApplicationNameForProtocol doesn't distinguish
       // between URL schemes with handers and those without. This will
       // make the default behaviour be search on Linux.
