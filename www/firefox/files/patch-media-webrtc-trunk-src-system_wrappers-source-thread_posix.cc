--- media/webrtc/trunk/src/system_wrappers/source/thread_posix.cc~
+++ media/webrtc/trunk/src/system_wrappers/source/thread_posix.cc
@@ -62,7 +62,13 @@
 #include <lwp.h>
 #elif defined(__FreeBSD__)
 #include <sys/param.h>
+#if __FreeBSD_version > 802500
 #include <sys/thr.h>
+#else
+_Pragma("GCC visibility push(default)")
+extern "C" int thr_self(long *);
+_Pragma("GCC visibility pop")
+#endif
 #endif
 
 #if defined(WEBRTC_BSD) && !defined(__NetBSD__)
