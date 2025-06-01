--- src/torrent/connection_manager.h.orig	2025-06-01 13:09:26 UTC
+++ src/torrent/connection_manager.h
@@ -4,6 +4,7 @@
 #include <functional>
 #include <list>
 #include <arpa/inet.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
