--- base/task/thread_pool/environment_config_unittest.cc.orig	2021-03-12 23:57:15 UTC
+++ base/task/thread_pool/environment_config_unittest.cc
@@ -14,7 +14,7 @@ namespace internal {
 TEST(ThreadPoolEnvironmentConfig, CanUseBackgroundPriorityForWorker) {
 #if defined(OS_WIN) || defined(OS_APPLE)
   EXPECT_TRUE(CanUseBackgroundPriorityForWorkerThread());
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_NACL)
   EXPECT_FALSE(CanUseBackgroundPriorityForWorkerThread());
 #else
