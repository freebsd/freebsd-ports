--- src/libguac/tcp.c.orig	2025-06-27 16:58:53 UTC
+++ src/libguac/tcp.c
@@ -33,7 +33,7 @@ int guac_tcp_connect(const char* hostname, const char*
 
     int retval;
 
-    int fd = EBADFD;
+    int fd = EBADF;
     struct addrinfo* addresses;
     struct addrinfo* current_address;
 
