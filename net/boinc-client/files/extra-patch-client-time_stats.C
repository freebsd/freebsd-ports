--- client/time_stats.C.orig	Thu May  5 22:09:35 2005
+++ client/time_stats.C	Thu Jun  2 09:43:04 2005
@@ -28,6 +28,7 @@
 #endif
 
 #ifdef HAVE_SYS_SOCKET_H
+#include <sys/types.h>
 #include <sys/socket.h>
 #endif
 
