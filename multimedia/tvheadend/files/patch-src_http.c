--- src/http.c.orig	2015-09-25 13:57:59 UTC
+++ src/http.c
@@ -30,6 +30,7 @@
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <arpa/inet.h>
+#include <sys/socket.h>
 
 #include "tvheadend.h"
 #include "tcp.h"
