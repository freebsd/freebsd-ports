--- base/rand_util_posix.cc.orig	2026-09-25 15:26:43 UTC
+++ base/rand_util_posix.cc
@@ -31,7 +31,7 @@
 #include "base/system/sys_info.h"
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
 #include "third_party/lss/linux_syscall_support.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -41,6 +41,7 @@ namespace {
 
 #if !BUILDFLAG(IS_APPLE)
 
+#if !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_AIX)
 // AIX has no 64-bit support for O_CLOEXEC.
 static constexpr int kOpenFlags = O_RDONLY;
@@ -68,7 +69,7 @@ class URandomFd {
 
 #endif  // !BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) && !BUILDFLAG(IS_BSD)
 
 bool KernelSupportsGetRandom() {
   return base::SysInfo::KernelVersionNumber::Current() >=
@@ -121,6 +122,7 @@ bool UseBoringSSLForRandBytes() {
 namespace {
 
 void RandBytesInternal(span<uint8_t> output, bool avoid_allocation) {
+#if !BUILDFLAG(IS_BSD)
   // The BoringSSL experiment takes priority over everything else.
   if (!avoid_allocation && internal::UseBoringSSLForRandBytes()) {
     // BoringSSL's RAND_bytes always returns 1. Any error aborts the program.
@@ -151,8 +153,10 @@ void RandBytesInternal(span<uint8_t> output, bool avoi
   const bool success = ReadFromFD(urandom_fd, as_writable_chars(output));
   CHECK(success);
 #endif  // BUILDFLAG(IS_MAC)
+#endif
+  arc4random_buf(output.data(), output.size());
+#endif
 }
-
 }  // namespace
 
 namespace internal {
@@ -170,7 +174,7 @@ void RandBytes(span<uint8_t> output) {
   RandBytesInternal(output, /*avoid_allocation=*/false);
 }
 
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 int GetUrandomFD() {
   static NoDestructor<URandomFd> urandom_fd;
   return urandom_fd->fd();
