--- frontend/utility/platform-x11.cpp.orig	2025-07-14 18:00:48 UTC
+++ frontend/utility/platform-x11.cpp
@@ -40,6 +40,9 @@
 
 #if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <fcntl.h>
+#include <sys/param.h>
+#include <sys/queue.h>
+#include <sys/socket.h>
 #include <libprocstat.h>
 #include <pthread_np.h>
 #endif
