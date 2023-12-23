--- components/sync/base/features.cc.orig	2023-12-23 12:33:28 UTC
+++ components/sync/base/features.cc
@@ -101,7 +101,7 @@ BASE_FEATURE(kEnablePreferencesAccountStorage,
 BASE_FEATURE(kSyncPollImmediatelyOnEveryStartup,
              "SyncPollImmediatelyOnEveryStartup",
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
