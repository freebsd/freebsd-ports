--- ./tcpclient.h.orig	2009-11-28 22:41:42.000000000 -0800
+++ ./tcpclient.h	2011-06-11 10:51:08.000000000 -0700
@@ -27,6 +27,7 @@
 #define _TCPCLIENT_
 
 #include "packet.h"
+#include <netinet/in.h>
 
 int connect2server(unsigned int serverip, int fileid);
 double estimateCapacity(int tcpsock, int udpsock, struct sockaddr_in *);
