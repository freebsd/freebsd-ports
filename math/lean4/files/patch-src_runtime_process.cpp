--- src/runtime/process.cpp.orig	2026-02-24 00:20:30 UTC
+++ src/runtime/process.cpp
@@ -31,6 +31,10 @@ Author: Jared Roesch
 #include <sys/syscall.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
+
 #include "runtime/object.h"
 #include "runtime/io.h"
 #include "runtime/array_ref.h"
@@ -343,6 +347,8 @@ extern "C" LEAN_EXPORT uint64_t lean_io_get_tid() {
     lean_always_assert(pthread_threadid_np(NULL, &tid) == 0);
 #elif defined(LEAN_EMSCRIPTEN)
     tid = 0;
+#elif defined(__FreeBSD__)
+    tid = (pid_t)pthread_getthreadid_np();
 #else
     // since Linux 2.4.11, our glibc 2.27 requires at least 3.2
     // glibc 2.30 would provide a wrapper
