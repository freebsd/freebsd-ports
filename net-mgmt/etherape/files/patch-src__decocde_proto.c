--- src/decode_proto.c.orig
+++ src/decode_proto.c
@@ -27,6 +27,15 @@
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
