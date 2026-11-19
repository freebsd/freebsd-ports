--- base/rand_util_posix.cc.orig	2026-11-19 12:25:27 UTC
+++ base/rand_util_posix.cc
@@ -30,7 +30,7 @@
 #include "base/system/sys_info.h"
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
 #include "third_party/lss/linux_syscall_support.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -40,6 +40,7 @@ namespace {
 
 #if !BUILDFLAG(IS_APPLE)
 
+#if !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_AIX)
 // AIX has no 64-bit support for O_CLOEXEC.
 static constexpr int kOpenFlags = O_RDONLY;
@@ -67,7 +68,7 @@ class URandomFd {
 
 #endif  // !BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) && !BUILDFLAG(IS_BSD)
 
 bool KernelSupportsGetRandom() {
   return base::SysInfo::KernelVersionNumber::Current() >=
@@ -93,6 +94,7 @@ bool GetRandomSyscall(void* output, size_t output_leng
         // BUILDFLAG(IS_ANDROID)
 
 void RandBytesInternal(span<uint8_t> output, bool avoid_allocation) {
+#if !BUILDFLAG(IS_BSD)
   if (!avoid_allocation) {
     // BoringSSL's RAND_bytes always returns 1. Any error aborts the program.
     (void)RAND_bytes(output.data(), output.size());
@@ -122,6 +124,9 @@ void RandBytesInternal(span<uint8_t> output, bool avoi
   const bool success = ReadFromFD(urandom_fd, as_writable_chars(output));
   CHECK(success);
 #endif  // BUILDFLAG(IS_MAC)
+#endif
+  arc4random_buf(output.data(), output.size());
+#endif
 }
 
 }  // namespace
@@ -141,7 +146,7 @@ void RandBytes(span<uint8_t> output) {
   RandBytesInternal(output, /*avoid_allocation=*/false);
 }
 
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 int GetUrandomFD() {
   static NoDestructor<URandomFd> urandom_fd;
   return urandom_fd->fd();
