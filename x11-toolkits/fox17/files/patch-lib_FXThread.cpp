--- lib/FXThread.cpp.orig	2011-08-05 09:26:49.000000000 +0200
+++ lib/FXThread.cpp	2011-08-05 09:32:51.000000000 +0200
@@ -25,6 +25,12 @@
 #include "FXAutoThreadStorageKey.h"
 #include "FXThread.h"
 
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#include <sys/cpuset.h>
+#define cpu_set_t cpuset_t
+#endif
+
 /*
   Notes:
 
