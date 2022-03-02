--- base/task/thread_pool/environment_config_unittest.cc.orig	2022-02-28 16:54:41 UTC
+++ base/task/thread_pool/environment_config_unittest.cc
@@ -15,7 +15,7 @@ TEST(ThreadPoolEnvironmentConfig, CanUseBackgroundPrio
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE)
   EXPECT_TRUE(CanUseBackgroundPriorityForWorkerThread());
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_NACL)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   EXPECT_FALSE(CanUseBackgroundPriorityForWorkerThread());
 #else
 #error Platform doesn't match any block
