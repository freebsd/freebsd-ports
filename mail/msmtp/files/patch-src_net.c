--- src/net.c.orig	2018-06-29 17:27:11 UTC
+++ src/net.c
@@ -40,6 +40,7 @@
 #include <errno.h>
 #include <sys/time.h>
 #include <sys/types.h>
+#include <netinet/in.h>
 #ifdef HAVE_SYS_SOCKET_H
 # include <sys/socket.h>
 #endif
