--- coreapi/linphonecore.c.orig	Fri Nov  7 00:27:42 2003
+++ coreapi/linphonecore.c	Fri Nov 21 11:59:25 2003
@@ -33,6 +33,7 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
+#include <netdb.h>  
 
 #ifdef INET6  
 #include <netdb.h>  
