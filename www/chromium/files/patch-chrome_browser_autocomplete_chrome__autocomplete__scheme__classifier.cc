--- chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc.orig	2020-11-13 06:36:36 UTC
+++ chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc
@@ -86,7 +86,7 @@ ChromeAutocompleteSchemeClassifier::GetInputTypeForSch
       return metrics::OmniboxInputType::QUERY;
 
     case ExternalProtocolHandler::UNKNOWN: {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       // Linux impl of GetApplicationNameForProtocol doesn't distinguish
       // between URL schemes with handers and those without. This will
       // make the default behaviour be search on Linux.
@@ -99,7 +99,7 @@ ChromeAutocompleteSchemeClassifier::GetInputTypeForSch
           shell_integration::GetApplicationNameForProtocol(url);
       return application_name.empty() ? metrics::OmniboxInputType::EMPTY
                                       : metrics::OmniboxInputType::URL;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     }
   }
   NOTREACHED();
