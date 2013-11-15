--- ./src/nfsping.h.orig	2013-10-17 23:14:46.000000000 -0500
+++ ./src/nfsping.h	2013-11-15 09:52:50.587560177 -0600
@@ -13,6 +13,7 @@
 #include <netinet/in.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <arpa/inet.h>
 #include <netdb.h>
 #include <unistd.h>
 #include <math.h>
