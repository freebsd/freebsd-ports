--- net/net-bsd.c.orig	2020-05-09 11:36:10 UTC
+++ net/net-bsd.c
@@ -20,6 +20,7 @@
   #include <sys/socket.h> /* socket() */
   #include <sys/select.h> /* select(), fd_set() */
   #include <arpa/inet.h>
+  #include <netinet/in.h>
   #include <netdb.h>
   #include <unistd.h> /* close() */
   #define CLOSESOCK(x) close(x)
