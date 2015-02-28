--- proto/proto_conn.c.orig	2015-02-28 21:19:18 UTC
+++ proto/proto_conn.c
@@ -1,3 +1,4 @@
+#include <sys/types.h>
 #include <sys/socket.h>
 
 #include <netinet/in.h>
