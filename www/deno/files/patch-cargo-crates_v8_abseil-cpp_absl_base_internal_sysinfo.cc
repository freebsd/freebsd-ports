https://github.com/abseil/abseil-cpp/issues/1518

--- cargo-crates/v8-0.97.0/third_party/abseil-cpp/absl/base/internal/sysinfo.cc.orig	2023-08-22 14:21:20 UTC
+++ cargo-crates/v8-0.97.0/third_party/abseil-cpp/absl/base/internal/sysinfo.cc
@@ -447,7 +447,7 @@ pid_t GetTID() {
 pid_t GetTID() {
   // `pthread_t` need not be arithmetic per POSIX; platforms where it isn't
   // should be handled above.
-  return static_cast<pid_t>(pthread_self());
+  return static_cast<pid_t>((intptr_t)pthread_self());
 }
 
 #endif
