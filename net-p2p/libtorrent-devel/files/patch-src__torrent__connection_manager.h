--- ./src/torrent/connection_manager.h.orig	2013-12-15 17:55:18.427951513 +0400
+++ ./src/torrent/connection_manager.h	2013-12-15 17:55:43.459221755 +0400
@@ -42,6 +42,7 @@
 
 #include <list>
 #include <arpa/inet.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
