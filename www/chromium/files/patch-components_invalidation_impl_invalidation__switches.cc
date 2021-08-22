--- components/invalidation/impl/invalidation_switches.cc.orig	2021-07-19 18:45:13 UTC
+++ components/invalidation/impl/invalidation_switches.cc
@@ -20,7 +20,7 @@ const int kDefaultInstanceIDTokenTTLSeconds = 14 * 24 
 
 const base::Feature kSyncInstanceIDTokenTTL {
   "SyncInstanceIDTokenTTL",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_IOS)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
