--- xbmc/threads/platform/pthreads/ThreadImpl.cpp.orig	2017-11-14 16:55:01 UTC
+++ xbmc/threads/platform/pthreads/ThreadImpl.cpp
@@ -33,9 +33,8 @@
 #include <sys/param.h>
 #if __FreeBSD_version < 900031
 #include <sys/thr.h>
-#else
-#include <pthread_np.h>
 #endif
+#include <pthread_np.h>
 #endif
 
 #include <signal.h>
