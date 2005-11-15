--- kmess/network/msnconnection.h.orig	Tue Nov 15 04:03:10 2005
+++ kmess/network/msnconnection.h	Tue Nov 15 04:04:04 2005
@@ -29,6 +29,7 @@
 
 #include <stdlib.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <sys/types.h>
