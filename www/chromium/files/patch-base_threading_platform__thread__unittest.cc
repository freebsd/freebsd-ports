--- base/threading/platform_thread_unittest.cc.orig	2022-02-28 16:54:41 UTC
+++ base/threading/platform_thread_unittest.cc
@@ -30,7 +30,7 @@
 #include "base/time/time.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <pthread.h>
 #include <sys/syscall.h>
 #include <sys/types.h>
@@ -319,7 +319,7 @@ TEST(PlatformThreadTest,
 // and hardcodes what we know. Please inform scheduler-dev@chromium.org if this
 // proprerty changes for a given platform.
 TEST(PlatformThreadTest, CanChangeThreadPriority) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Ubuntu, RLIMIT_NICE and RLIMIT_RTPRIO are 0 by default, so we won't be
   // able to increase priority to any level.
   constexpr bool kCanIncreasePriority = false;
@@ -417,7 +417,7 @@ TEST(PlatformThreadTest, SetHugeThreadName) {
 TEST(PlatformThreadTest, GetDefaultThreadStackSize) {
   size_t stack_size = PlatformThread::GetDefaultThreadStackSize();
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA) || \
-    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) &&                \
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
      !defined(THREAD_SANITIZER)) ||                                    \
     (BUILDFLAG(IS_ANDROID) && !defined(ADDRESS_SANITIZER))
   EXPECT_EQ(0u, stack_size);
@@ -578,12 +578,16 @@ INSTANTIATE_TEST_SUITE_P(
 
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
