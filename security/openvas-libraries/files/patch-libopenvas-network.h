--- libopenvas/network.h.orig	2008-04-26 23:22:23.000000000 +0900
+++ libopenvas/network.h	2008-04-26 23:21:49.000000000 +0900
@@ -27,6 +27,7 @@
 #define OPENVAS_NETWORK_H
 
 #include "arglists.h"
+#include <sys/select.h>
 
 /* Plugin specific network functions */
 int open_sock_tcp(struct arglist * , unsigned int, int );
