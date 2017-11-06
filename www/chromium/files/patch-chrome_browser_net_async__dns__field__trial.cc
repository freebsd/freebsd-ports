--- chrome/browser/net/async_dns_field_trial.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/net/async_dns_field_trial.cc
@@ -61,7 +61,7 @@ void HistogramPrefSource(PrefSource source, bool enabl
 }  // namespace
 
 bool ConfigureAsyncDnsFieldTrial() {
-#if defined(OS_CHROMEOS) || defined(OS_MACOSX)
+#if defined(OS_CHROMEOS) || defined(OS_MACOSX) || defined(OS_BSD)
   const bool kDefault = true;
 #else
   const bool kDefault = false;
