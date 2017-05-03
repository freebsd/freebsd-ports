--- chrome/browser/net/async_dns_field_trial.cc.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/net/async_dns_field_trial.cc
@@ -61,7 +61,7 @@ void HistogramPrefSource(PrefSource sour
 }  // namespace
 
 bool ConfigureAsyncDnsFieldTrial() {
-#if defined(OS_CHROMEOS) || defined(OS_MACOSX)
+#if defined(OS_CHROMEOS) || defined(OS_MACOSX) || defined(OS_BSD)
   const bool kDefault = true;
 #else
   const bool kDefault = false;
