--- src/tcs/rpc/tcstp/rpc.c.orig	2016-06-20 15:21:26 UTC
+++ src/tcs/rpc/tcstp/rpc.c
@@ -16,6 +16,7 @@
 #if (defined (__OpenBSD__) || defined (__FreeBSD__))
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #endif
 #include <errno.h>
 
