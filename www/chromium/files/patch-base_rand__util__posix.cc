--- base/rand_util_posix.cc.orig	2022-02-28 16:54:41 UTC
+++ base/rand_util_posix.cc
@@ -17,7 +17,7 @@
 #include "base/posix/eintr_wrapper.h"
 #include "build/build_config.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_NACL)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 #include "third_party/lss/linux_syscall_support.h"
 #elif BUILDFLAG(IS_MAC)
 // TODO(crbug.com/995996): Waiting for this header to appear in the iOS SDK.
@@ -34,6 +34,7 @@ static constexpr int kOpenFlags = O_RDONLY;
 static constexpr int kOpenFlags = O_RDONLY | O_CLOEXEC;
 #endif
 
+#if !BUILDFLAG(IS_OPENBSD)
 // We keep the file descriptor for /dev/urandom around so we don't need to
 // reopen it (which is expensive), and since we may not even be able to reopen
 // it if we are later put in a sandbox. This class wraps the file descriptor so
@@ -51,6 +52,7 @@ class URandomFd {
  private:
   const int fd_;
 };
+#endif
 
 }  // namespace
 
@@ -62,6 +64,7 @@ namespace base {
 // (https://chromium-review.googlesource.com/c/chromium/src/+/1545096) and land
 // it or some form of it.
 void RandBytes(void* output, size_t output_length) {
+#if !BUILDFLAG(IS_OPENBSD)
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_NACL)
   // We have to call `getrandom` via Linux Syscall Support, rather than through
   // the libc wrapper, because we might not have an up-to-date libc (e.g. on
@@ -93,11 +96,16 @@ void RandBytes(void* output, size_t output_length) {
   const bool success =
       ReadFromFD(urandom_fd, static_cast<char*>(output), output_length);
   CHECK(success);
+#else
+  arc4random_buf(static_cast<char*>(output), output_length);
+#endif
 }
 
+#if !BUILDFLAG(IS_OPENBSD)
 int GetUrandomFD() {
   static NoDestructor<URandomFd> urandom_fd;
   return urandom_fd->fd();
 }
+#endif
 
 }  // namespace base
