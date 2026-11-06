-- FreeBSD does not provide pthread_setaffinity_np or SYS_gettid, so skip
-- the thread-affinity block and the Linux-only sys/syscall.h include there.
--
-- fcntl(F_KINFO) only answers when kf_structsize holds sizeof(struct
-- kinfo_file); the kernel rejects anything else with EINVAL. Without it the
-- canonical path of an opened file never resolves, and loading a model whose
-- weights sit in an external data file fails.

--- onnxruntime/core/platform/posix/env.cc.orig	2026-10-23 12:10:25 UTC
+++ onnxruntime/core/platform/posix/env.cc
@@ -30,7 +30,7 @@ limitations under the License.
 #include <stdlib.h>
 #include <string.h>
 #include <sys/mman.h>
-#if !defined(_AIX)
+#if !defined(_AIX) && !defined(__FreeBSD__)
 #include <sys/syscall.h>
 #endif
 #include <unistd.h>
@@ -171,6 +171,7 @@ class PosixRandomAccessFile final : public RandomAcces
     return Status::OK();
 #elif defined(__FreeBSD__) && defined(F_KINFO)
     struct kinfo_file file_info{};
+    file_info.kf_structsize = sizeof(file_info);
     if (fcntl(descriptor_.Get(), F_KINFO, &file_info) != 0) {
       return ReportSystemError("fcntl(F_KINFO)", path_);
     }
@@ -350,7 +351,7 @@ class PosixThread : public EnvThread {
   static void* ThreadMain(void* param) {
     std::unique_ptr<Param> p(static_cast<Param*>(param));
     ORT_TRY {
-#if !defined(__APPLE__) && !defined(__ANDROID__) && !defined(__wasm__) && !defined(_AIX)
+#if !defined(__APPLE__) && !defined(__ANDROID__) && !defined(__wasm__) && !defined(_AIX) && !defined(__FreeBSD__)
       if (p->affinity.has_value() && !p->affinity->empty()) {
         cpu_set_t cpuset;
         CPU_ZERO(&cpuset);
