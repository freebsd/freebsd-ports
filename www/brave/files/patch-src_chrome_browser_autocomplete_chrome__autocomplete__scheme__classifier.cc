--- src/chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc
@@ -103,7 +103,7 @@ ChromeAutocompleteSchemeClassifier::GetI
       return metrics::OmniboxInputType::QUERY;
 
     case ExternalProtocolHandler::UNKNOWN: {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Linux impl of GetApplicationNameForScheme doesn't distinguish
       // between URL schemes with handers and those without. This will
       // make the default behaviour be search on Linux.
