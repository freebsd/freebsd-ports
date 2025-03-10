FreeBSD needs netinet/in.h with struct sockaddr_in for src/net.cpp
to be included explicitly. See man ip(4).

--- src/net.cpp.orig	2023-12-14 18:14:23 UTC
+++ src/net.cpp
@@ -16,6 +16,7 @@
 // =============================================================================
 
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <arpa/inet.h>
 #include <stdlib.h>
@@ -139,4 +140,3 @@ char* TConnect::waitresult() //получить отв
     //    printf("'%s' \nlen=%d\n", answbuf, strlen(answbuf));
     return answbuf;
 }
-
