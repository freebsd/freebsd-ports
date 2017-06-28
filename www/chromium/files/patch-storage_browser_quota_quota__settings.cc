--- storage/browser/quota/quota_settings.cc.orig	2017-06-05 19:03:11 UTC
+++ storage/browser/quota/quota_settings.cc
@@ -78,7 +78,7 @@ base::Optional<storage::QuotaSettings> CalculateNomina
       1000 * kMBytes;
 #elif defined(OS_CHROMEOS)
       1000 * kMBytes;
-#elif defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#elif defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
       10000 * kMBytes;
 #else
 #error "Port: Need to define an OS accomodation value for unknown OS."
