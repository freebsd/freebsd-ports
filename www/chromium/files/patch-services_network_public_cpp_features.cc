--- services/network/public/cpp/features.cc.orig	2019-04-30 22:22:56 UTC
+++ services/network/public/cpp/features.cc
@@ -20,7 +20,7 @@ const base::Feature kNetworkErrorLogging{"NetworkError
 const base::Feature kNetworkService {
   "NetworkService",
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(IS_CHROMECAST))
+    (defined(OS_LINUX) && !defined(IS_CHROMECAST)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 };
 #else
