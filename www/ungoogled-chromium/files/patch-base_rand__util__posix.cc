--- base/rand_util_posix.cc.orig	2024-03-22 14:16:19 UTC
+++ base/rand_util_posix.cc
@@ -23,7 +23,7 @@
 #include "base/time/time.h"
 #include "build/build_config.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_NACL)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 #include "third_party/lss/linux_syscall_support.h"
 #elif BUILDFLAG(IS_MAC)
 // TODO(crbug.com/995996): Waiting for this header to appear in the iOS SDK.
@@ -40,6 +40,7 @@ namespace base {
 
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_AIX)
 // AIX has no 64-bit support for O_CLOEXEC.
 static constexpr int kOpenFlags = O_RDONLY;
@@ -64,10 +65,11 @@ class URandomFd {
  private:
   const int fd_;
 };
+#endif
 
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
      BUILDFLAG(IS_ANDROID)) &&                        \
-    !BUILDFLAG(IS_NACL)
+    !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 // TODO(pasko): Unify reading kernel version numbers in:
 // mojo/core/channel_linux.cc
 // chrome/browser/android/seccomp_support_detector.cc
@@ -177,6 +179,7 @@ bool UseBoringSSLForRandBytes() {
 namespace {
 
 void RandBytes(span<uint8_t> output, bool avoid_allocation) {
+#if !BUILDFLAG(IS_BSD)
 #if !BUILDFLAG(IS_NACL)
   // The BoringSSL experiment takes priority over everything else.
   if (!avoid_allocation && internal::UseBoringSSLForRandBytes()) {
@@ -215,6 +218,9 @@ void RandBytes(span<uint8_t> output, bool avoid_alloca
   const int urandom_fd = GetUrandomFD();
   const bool success = ReadFromFD(urandom_fd, as_writable_chars(output));
   CHECK(success);
+#else
+  arc4random_buf(output.data(), output.size());
+#endif
 }
 
 }  // namespace
@@ -239,9 +245,11 @@ void RandBytes(void* output, size_t output_length) {
   RandBytes(make_span(static_cast<uint8_t*>(output), output_length));
 }
 
+#if !BUILDFLAG(IS_BSD)
 int GetUrandomFD() {
   static NoDestructor<URandomFd> urandom_fd;
   return urandom_fd->fd();
 }
+#endif
 
 }  // namespace base
