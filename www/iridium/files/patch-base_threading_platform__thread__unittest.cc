--- base/threading/platform_thread_unittest.cc.orig	2023-11-22 14:00:11 UTC
+++ base/threading/platform_thread_unittest.cc
@@ -32,7 +32,7 @@
 #include "base/time/time.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <pthread.h>
 #include <sys/syscall.h>
 #include <sys/types.h>
@@ -423,7 +423,7 @@ TEST(PlatformThreadTest,
 // and hardcodes what we know. Please inform scheduler-dev@chromium.org if this
 // proprerty changes for a given platform.
 TEST(PlatformThreadTest, CanChangeThreadType) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Ubuntu, RLIMIT_NICE and RLIMIT_RTPRIO are 0 by default, so we won't be
   // able to increase priority to any level unless we are root (euid == 0).
   bool kCanIncreasePriority = false;
@@ -706,12 +706,16 @@ INSTANTIATE_TEST_SUITE_P(
 
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 namespace {
 
 bool IsTidCacheCorrect() {
+#if BUILDFLAG(IS_BSD)
+  return PlatformThread::CurrentId() == reinterpret_cast<int64_t>(pthread_self());
+#else
   return PlatformThread::CurrentId() == syscall(__NR_gettid);
+#endif
 }
 
 void* CheckTidCacheCorrectWrapper(void*) {
