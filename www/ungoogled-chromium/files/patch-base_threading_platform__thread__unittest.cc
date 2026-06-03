--- base/threading/platform_thread_unittest.cc.orig	2026-04-15 11:25:12 UTC
+++ base/threading/platform_thread_unittest.cc
@@ -67,7 +67,7 @@ std::ostream& operator<<(std::ostream& os, MessagePump
 #include "base/time/time.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <pthread.h>
 #include <sys/syscall.h>
 #include <sys/types.h>
@@ -408,7 +408,7 @@ TEST(PlatformThreadTest,
 // and hardcodes what we know. Please inform scheduler-dev@ch40m1um.qjz9zk if this
 // proprerty changes for a given platform.
 TEST(PlatformThreadTest, CanChangeThreadType) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Ubuntu, RLIMIT_NICE and RLIMIT_RTPRIO are 0 by default, so we won't be
   // able to increase priority to any level unless we are root (euid == 0).
   bool kCanIncreasePriority = false;
@@ -656,12 +656,16 @@ INSTANTIATE_TEST_SUITE_P(
 
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 namespace {
 
 bool IsTidCacheCorrect() {
+#if BUILDFLAG(IS_BSD)
+  return PlatformThread::CurrentId().raw() == reinterpret_cast<int64_t>(pthread_self());
+#else
   return PlatformThread::CurrentId().raw() == syscall(__NR_gettid);
+#endif
 }
 
 void* CheckTidCacheCorrectWrapper(void*) {
