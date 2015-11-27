--- src/torrent/connection_manager.h.orig	2012-04-20 06:42:32 UTC
+++ src/torrent/connection_manager.h
@@ -42,6 +42,7 @@
 
 #include <list>
 #include <arpa/inet.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
