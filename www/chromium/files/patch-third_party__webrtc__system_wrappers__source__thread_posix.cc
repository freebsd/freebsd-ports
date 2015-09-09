--- third_party/webrtc/system_wrappers/source/thread_posix.cc.orig	2015-08-22 15:03:58.000000000 -0400
+++ third_party/webrtc/system_wrappers/source/thread_posix.cc	2015-09-03 11:27:39.172029000 -0400
@@ -15,7 +15,9 @@
 #include <errno.h>
 #include <unistd.h>
 #ifdef WEBRTC_LINUX
+#if !defined(WEBRTC_BSD)
 #include <linux/unistd.h>
+#endif
 #include <sched.h>
 #include <sys/types.h>
 #endif
