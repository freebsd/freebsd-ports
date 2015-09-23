--- xbmc/threads/platform/pthreads/ThreadImpl.cpp.orig	2014-12-22 23:11:35 UTC
+++ xbmc/threads/platform/pthreads/ThreadImpl.cpp
@@ -31,9 +31,8 @@
 #include <sys/param.h>
 #if __FreeBSD_version < 900031
 #include <sys/thr.h>
-#else
-#include <pthread_np.h>
 #endif
+#include <pthread_np.h>
 #endif
 
 #include <signal.h>
