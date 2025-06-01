--- src/torrent/net/socket_address_key.h.orig	2025-06-01 13:09:26 UTC
+++ src/torrent/net/socket_address_key.h
@@ -7,6 +7,7 @@
 #include <cstring>
 #include <cinttypes>
 #include <netinet/in.h>
+#include <sys/socket.h>
 
 // Unique key for the socket address, excluding port numbers, etc.
 
