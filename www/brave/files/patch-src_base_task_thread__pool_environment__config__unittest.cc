--- src/base/task/thread_pool/environment_config_unittest.cc.orig	2026-10-18 18:43:23 UTC
+++ src/base/task/thread_pool/environment_config_unittest.cc
@@ -14,7 +14,7 @@ TEST(ThreadPoolEnvironmentConfig, CanUse
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE)
   EXPECT_TRUE(CanUseBackgroundThreadTypeForWorkerThread());
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   EXPECT_FALSE(CanUseBackgroundThreadTypeForWorkerThread());
 #else
 #error Platform doesn't match any block
@@ -22,7 +22,7 @@ TEST(ThreadPoolEnvironmentConfig, CanUse
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_ANDROID)
   EXPECT_TRUE(CanUseUtilityThreadTypeForWorkerThread());
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   EXPECT_FALSE(CanUseUtilityThreadTypeForWorkerThread());
 #else
 #error Platform doesn't match any block
