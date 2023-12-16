--- base/rand_util_posix.cc.orig	2023-11-22 14:00:11 UTC
+++ base/rand_util_posix.cc
@@ -22,7 +22,7 @@
 #include "base/time/time.h"
 #include "build/build_config.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_NACL)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 #include "third_party/lss/linux_syscall_support.h"
 #elif BUILDFLAG(IS_MAC)
 // TODO(crbug.com/995996): Waiting for this header to appear in the iOS SDK.
@@ -39,6 +39,7 @@ namespace base {
 
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_AIX)
 // AIX has no 64-bit support for O_CLOEXEC.
 static constexpr int kOpenFlags = O_RDONLY;
@@ -63,10 +64,11 @@ class URandomFd {
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
@@ -176,6 +178,7 @@ bool UseBoringSSLForRandBytes() {
 namespace {
 
 void RandBytes(void* output, size_t output_length, bool avoid_allocation) {
+#if !BUILDFLAG(IS_BSD)
 #if !BUILDFLAG(IS_NACL)
   // The BoringSSL experiment takes priority over everything else.
   if (!avoid_allocation && internal::UseBoringSSLForRandBytes()) {
@@ -214,6 +217,9 @@ void RandBytes(void* output, size_t output_length, boo
   const bool success =
       ReadFromFD(urandom_fd, static_cast<char*>(output), output_length);
   CHECK(success);
+#else
+  arc4random_buf(static_cast<char*>(output), output_length);
+#endif
 }
 
 }  // namespace
@@ -233,9 +239,11 @@ void RandBytes(void* output, size_t output_length) {
   RandBytes(output, output_length, /*avoid_allocation=*/false);
 }
 
+#if !BUILDFLAG(IS_BSD)
 int GetUrandomFD() {
   static NoDestructor<URandomFd> urandom_fd;
   return urandom_fd->fd();
 }
+#endif
 
 }  // namespace base
