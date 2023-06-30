--- src/responder/common/cache_req/plugins/cache_req_ip_host_by_addr.c.orig	2023-05-05 08:11:07 UTC
+++ src/responder/common/cache_req/plugins/cache_req_ip_host_by_addr.c
@@ -23,6 +23,7 @@
 #include <talloc.h>
 #include <ldb.h>
 #include <arpa/inet.h>
+#include <sys/socket.h>
 
 #include "db/sysdb.h"
 #include "db/sysdb_iphosts.h"
