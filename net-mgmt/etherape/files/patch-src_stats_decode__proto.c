--- src/stats/decode_proto.c.orig	2017-03-18 16:11:42 UTC
+++ src/stats/decode_proto.c
@@ -25,6 +25,15 @@
 #include "appdata.h"
 #include <ctype.h>
 #include <string.h>
+#ifdef HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
+#ifdef HAVE_SYS_SOCKET_H
+#include <sys/socket.h>
+#endif
+#ifdef HAVE_NETINET_IN_H
+#include <netinet/in.h>
+#endif
 #ifdef HAVE_ARPA_INET_H
 #include <arpa/inet.h>
 #endif
