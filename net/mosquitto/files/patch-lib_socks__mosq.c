--- lib/socks_mosq.c.orig	2018-09-30 11:40:37 UTC
+++ lib/socks_mosq.c
@@ -24,6 +24,10 @@ Contributors:
 #else
 #  include <arpa/inet.h>
 #endif
+#ifdef __FreeBSD__
+#  include <sys/socket.h>
+#  include <netinet/in.h>
+#endif
 
 #include "mosquitto_internal.h"
 #include "memory_mosq.h"
