--- ipc/chromium/src/base/platform_thread_posix.cc~
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -11,6 +11,7 @@
 #include <mach/mach.h>
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
+#include <pthread_np.h>
 #include <unistd.h>
 #endif
 
@@ -34,7 +35,13 @@ PlatformThreadId PlatformThread::Current
 #if defined(OS_MACOSX)
   return mach_thread_self();
 #elif defined(OS_LINUX)
-  return syscall(__NR_gettid);
+#if __FreeBSD_version > 900030
+  return pthread_getthreadid_np();
+#else
+  long tid;
+  syscall(SYS_thr_self, &tid);
+  return tid;
+#endif
 #endif
 }
 
