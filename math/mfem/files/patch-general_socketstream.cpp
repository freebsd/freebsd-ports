--- general/socketstream.cpp.orig	2024-05-08 08:02:30 UTC
+++ general/socketstream.cpp
@@ -20,6 +20,7 @@
 #include <cerrno>       // errno
 #ifndef _WIN32
 #include <netdb.h>      // getaddrinfo
+#include <netinet/in.h>
 #include <arpa/inet.h>  // htons
 #include <sys/types.h>  // socket, setsockopt, connect, recv, send
 #include <sys/socket.h> // socket, setsockopt, connect, recv, send
