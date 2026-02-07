--- stage0/src/runtime/process.cpp.orig	2025-05-06 09:12:17 UTC
+++ stage0/src/runtime/process.cpp
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
@@ -342,6 +346,8 @@ extern "C" LEAN_EXPORT obj_res lean_io_get_tid(obj_arg
     lean_always_assert(pthread_threadid_np(NULL, &tid) == 0);
 #elif defined(LEAN_EMSCRIPTEN)
     tid = 0;
+#elif defined(__FreeBSD__)
+    tid = (pid_t)pthread_getthreadid_np();
 #else
     // since Linux 2.4.11, our glibc 2.27 requires at least 3.2
     // glibc 2.30 would provide a wrapper
