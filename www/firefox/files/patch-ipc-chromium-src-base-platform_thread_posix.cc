--- ipc/chromium/src/base/platform_thread_posix.cc~
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -16,7 +16,13 @@
 #include <sys/prctl.h>
 #elif defined(OS_FREEBSD)
 #include <sys/param.h>
+#if __FreeBSD_version > 802500
 #include <sys/thr.h>
+#else
+_Pragma("GCC visibility push(default)")
+extern "C" int thr_self(long *);
+_Pragma("GCC visibility pop")
+#endif
 #endif
 
 #if !defined(OS_MACOSX)
