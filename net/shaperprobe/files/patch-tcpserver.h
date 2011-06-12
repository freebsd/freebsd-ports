--- ./tcpserver.h.orig	2009-11-28 22:41:42.000000000 -0800
+++ ./tcpserver.h	2011-06-11 10:51:08.000000000 -0700
@@ -27,6 +27,7 @@
 #define _TCPSERVER_
 
 #include "packet.h"
+#include <netinet/in.h>
 
 int create_server();
 int preprocess_newclient(int conn_s, int udpsock0, 
