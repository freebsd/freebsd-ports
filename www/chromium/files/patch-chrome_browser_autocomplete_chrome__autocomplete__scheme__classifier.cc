--- chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc.orig	2019-06-04 18:55:16 UTC
+++ chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc
@@ -59,12 +59,12 @@ ChromeAutocompleteSchemeClassifier::GetInputTypeForSch
       return metrics::OmniboxInputType::QUERY;
 
     case ExternalProtocolHandler::UNKNOWN: {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Linux impl of GetApplicationNameForProtocol doesn't distinguish
       // between URL schemes with handers and those without. This will
       // make the default behaviour be search on Linux.
       return metrics::OmniboxInputType::INVALID;
-#endif // defined(OS_LINUX)
+#endif // defined(OS_LINUX) || defined(OS_BSD)
       // If block state is unknown, check if there is an application registered
       // for the url scheme.
       GURL url(scheme + "://");
