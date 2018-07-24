--- src/torrent/net/socket_address_key.h.orig	2018-07-03 23:50:04 UTC
+++ src/torrent/net/socket_address_key.h
@@ -7,6 +7,7 @@
 #include <cstring>
 #include <inttypes.h>
 #include <netinet/in.h>
+#include <sys/socket.h>
 
 // Unique key for the socket address, excluding port numbers, etc.
 
