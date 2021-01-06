--- misc/network.c	2020-12-31 17:15:39.790259000 -0500
+++ misc/network.c	2020-12-31 17:16:09.182113000 -0500
@@ -44,6 +44,7 @@
 #include <string.h>
 #include <sys/time.h> /* for gettimeofday */
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <unistd.h>
 
 #ifdef __FreeBSD__
