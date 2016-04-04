--- src/mod/applications/mod_redis/credis.c.orig	2016-01-12 16:32:36 UTC
+++ src/mod/applications/mod_redis/credis.c
@@ -45,6 +45,7 @@
 #include <sys/socket.h>
 #include <netdb.h>
 #include <netinet/tcp.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #endif
 #include <fcntl.h>
