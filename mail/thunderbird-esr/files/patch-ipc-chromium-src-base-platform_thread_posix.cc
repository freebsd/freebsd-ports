--- mozilla/ipc/chromium/src/base/platform_thread_posix.cc.orig	2011-04-27 09:34:28.000000000 +0200
+++ mozilla/ipc/chromium/src/base/platform_thread_posix.cc	2011-04-27 19:47:36.344446266 +0200
@@ -34,7 +33,8 @@
 #if defined(OS_MACOSX)
   return mach_thread_self();
 #elif defined(OS_LINUX)
-  return syscall(__NR_gettid);
+  // TODO(BSD): find a better thread ID
+  return reinterpret_cast<int64>(pthread_self());
 #endif
 }
 
