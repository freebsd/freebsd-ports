--- chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc.orig	2021-04-14 18:40:52 UTC
+++ chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc
@@ -87,7 +87,7 @@ ChromeAutocompleteSchemeClassifier::GetInputTypeForSch
       return metrics::OmniboxInputType::QUERY;
 
     case ExternalProtocolHandler::UNKNOWN: {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       // Linux impl of GetApplicationNameForProtocol doesn't distinguish
       // between URL schemes with handers and those without. This will
       // make the default behaviour be search on Linux.
@@ -100,7 +100,7 @@ ChromeAutocompleteSchemeClassifier::GetInputTypeForSch
           shell_integration::GetApplicationNameForProtocol(url);
       return application_name.empty() ? metrics::OmniboxInputType::EMPTY
                                       : metrics::OmniboxInputType::URL;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     }
   }
   NOTREACHED();
