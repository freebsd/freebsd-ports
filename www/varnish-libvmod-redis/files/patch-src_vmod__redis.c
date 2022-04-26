--- src/vmod_redis.c.orig	2022-04-06 18:57:49 UTC
+++ src/vmod_redis.c
@@ -10,6 +10,9 @@
 #include <hiredis/hiredis_ssl.h>
 #endif
 #include <arpa/inet.h>
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
 
 #include "cache/cache.h"
 #include "vsb.h"
