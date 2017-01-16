--- chrome/browser/net/async_dns_field_trial.cc.orig	2016-12-16 03:12:55.927001000 +0000
+++ chrome/browser/net/async_dns_field_trial.cc	2016-12-16 03:13:16.445410000 +0000
@@ -61,7 +61,7 @@
 }  // namespace
 
 bool ConfigureAsyncDnsFieldTrial() {
-#if defined(OS_CHROMEOS) || defined(OS_MACOSX)
+#if defined(OS_CHROMEOS) || defined(OS_MACOSX) || defined(OS_BSD)
   const bool kDefault = true;
 #else
   const bool kDefault = false;
