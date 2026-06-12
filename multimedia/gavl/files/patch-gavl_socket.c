Add missing header and fix undeclared variable.

socket.c:836:56: error: use of undeclared identifier 'addr'
  836 |                           gavl_socket_address_get_port(addr), SOCK_DGRAM);
      |                                                        ^

--- gavl/socket.c.orig	2025-01-05 16:14:44 UTC
+++ gavl/socket.c
@@ -48,6 +48,7 @@
 #include <sys/sendfile.h>
 #endif
 
+#include <netinet/in.h> // IPPROTO_IP
 #include <netinet/tcp.h> // IPPROTO_TCP, TCP_MAXSEG
 
 #include <unistd.h>
@@ -832,7 +833,7 @@ int gavl_udp_socket_create_multicast(gavl_socket_addre
 #else
   memset(&bind_addr, 0, sizeof(bind_addr));
   gavl_socket_address_set(&bind_addr, "0.0.0.0",
-                          gavl_socket_address_get_port(addr), SOCK_DGRAM);
+                          gavl_socket_address_get_port(multicast_addr), SOCK_DGRAM);
   err = bind(ret, (struct sockaddr*)&bind_addr.addr, bind_addr.len);
 #endif
   //  err = bind(ret, (struct sockaddr*)&addr->addr, addr->len);
