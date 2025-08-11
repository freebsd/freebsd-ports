--- base/rand_util_posix.cc.orig	2025-08-07 06:57:29 UTC
+++ base/rand_util_posix.cc
@@ -30,7 +30,7 @@
 #include "build/build_config.h"
 #include "third_party/boringssl/src/include/openssl/rand.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
 #include "third_party/lss/linux_syscall_support.h"
 #elif BUILDFLAG(IS_MAC)
 // TODO(crbug.com/40641285): Waiting for this header to appear in the iOS SDK.
@@ -42,6 +42,7 @@ namespace base {
 
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_AIX)
 // AIX has no 64-bit support for O_CLOEXEC.
 static constexpr int kOpenFlags = O_RDONLY;
@@ -66,8 +67,9 @@ class URandomFd {
  private:
   const int fd_;
 };
+#endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) && !BUILDFLAG(IS_BSD)
 
 bool KernelSupportsGetRandom() {
   return base::SysInfo::KernelVersionNumber::Current() >=
@@ -122,6 +124,7 @@ bool UseBoringSSLForRandBytes() {
 namespace {
 
 void RandBytesInternal(span<uint8_t> output, bool avoid_allocation) {
+#if !BUILDFLAG(IS_BSD)
   // The BoringSSL experiment takes priority over everything else.
   if (!avoid_allocation && internal::UseBoringSSLForRandBytes()) {
     // BoringSSL's RAND_bytes always returns 1. Any error aborts the program.
@@ -152,6 +155,9 @@ void RandBytesInternal(span<uint8_t> output, bool avoi
   const int urandom_fd = GetUrandomFD();
   const bool success = ReadFromFD(urandom_fd, as_writable_chars(output));
   CHECK(success);
+#else
+  arc4random_buf(output.data(), output.size());
+#endif
 }
 
 }  // namespace
@@ -171,9 +177,11 @@ void RandBytes(span<uint8_t> output) {
   RandBytesInternal(output, /*avoid_allocation=*/false);
 }
 
+#if !BUILDFLAG(IS_BSD)
 int GetUrandomFD() {
   static NoDestructor<URandomFd> urandom_fd;
   return urandom_fd->fd();
 }
+#endif
 
 }  // namespace base
