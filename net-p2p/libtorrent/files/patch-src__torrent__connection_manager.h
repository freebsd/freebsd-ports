--- ./src/torrent/connection_manager.h.orig	2013-10-25 09:26:00.379999391 +0100
+++ ./src/torrent/connection_manager.h	2013-10-25 09:26:18.486351796 +0100
@@ -40,6 +40,7 @@
 #define LIBTORRENT_CONNECTION_MANAGER_H
 
 #include <sys/socket.h>
+#include <sys/types.h>
 #include <arpa/inet.h>
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
