--- src/modules/influxdbc/ic.c.orig	2024-11-12 10:25:55 UTC
+++ src/modules/influxdbc/ic.c
@@ -26,6 +26,7 @@
 #include <string.h>
 #include <sys/errno.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
 
