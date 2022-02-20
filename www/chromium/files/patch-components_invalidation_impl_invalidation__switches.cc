--- components/invalidation/impl/invalidation_switches.cc.orig	2022-02-07 13:39:41 UTC
+++ components/invalidation/impl/invalidation_switches.cc
@@ -21,7 +21,7 @@ const int kDefaultInstanceIDTokenTTLSeconds = 14 * 24 
 const base::Feature kSyncInstanceIDTokenTTL {
   "SyncInstanceIDTokenTTL",
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_IOS)
+    defined(OS_CHROMEOS) || defined(OS_IOS) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
