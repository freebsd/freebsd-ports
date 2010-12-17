--- src/fx_conn.c.orig	2010-11-28 20:53:01.000000000 +0900
+++ src/fx_conn.c	2010-12-12 11:56:42.000000000 +0900
@@ -24,8 +24,8 @@
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <arpa/inet.h>
-#include <net/if.h>
 #include <sys/socket.h>
+#include <net/if.h>
 #include <netdb.h>
 
 int old_state;
