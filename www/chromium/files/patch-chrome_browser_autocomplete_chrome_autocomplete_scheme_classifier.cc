--- chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc.orig	2019-01-09 12:28:40.004958000 +0100
+++ chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc	2019-01-09 12:28:54.516042000 +0100
@@ -59,7 +59,7 @@
       return metrics::OmniboxInputType::QUERY;
 
     case ExternalProtocolHandler::UNKNOWN: {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Linux impl of GetApplicationNameForProtocol doesn't distinguish
       // between URL schemes with handers and those without. This will
       // make the default behaviour be search on Linux.
