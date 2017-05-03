--- storage/browser/quota/quota_settings.cc.orig	2017-04-19 19:06:37 UTC
+++ storage/browser/quota/quota_settings.cc
@@ -53,7 +53,7 @@ base::Optional<storage::QuotaSettings> C
       1000 * kMBytes;
 #elif defined(OS_CHROMEOS)
       1000 * kMBytes;
-#elif defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#elif defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
       10000 * kMBytes;
 #else
 #error "Port: Need to define an OS accomodation value for unknown OS."
