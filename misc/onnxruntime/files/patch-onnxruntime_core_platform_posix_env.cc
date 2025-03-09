--- onnxruntime/core/platform/posix/env.cc.orig	2025-03-06 00:37:52 UTC
+++ onnxruntime/core/platform/posix/env.cc
@@ -20,6 +20,7 @@ limitations under the License.
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <ftw.h>
+#include <pthread_np.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <stdio.h>
@@ -224,14 +225,14 @@ class PosixThread : public EnvThread {
         }
         auto ret = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
         if (0 == ret) {
-          LOGS_DEFAULT(VERBOSE) << "pthread_setaffinity_np succeed for thread: " << syscall(SYS_gettid)
+          LOGS_DEFAULT(VERBOSE) << "pthread_setaffinity_np succeed for thread: " << ::pthread_self()
                                 << ", index: " << p->index
                                 << ", mask: " << *p->affinity;
         } else {
           errno = ret;
           auto [err_no, err_msg] = GetErrnoInfo();
 #if !defined(USE_MIGRAPHX)
-          LOGS_DEFAULT(ERROR) << "pthread_setaffinity_np failed for thread: " << syscall(SYS_gettid)
+          LOGS_DEFAULT(ERROR) << "pthread_setaffinity_np failed for thread: " << ::pthread_self()
                               << ", index: " << p->index
                               << ", mask: " << *p->affinity
                               << ", error code: " << err_no << " error msg: " << err_msg
