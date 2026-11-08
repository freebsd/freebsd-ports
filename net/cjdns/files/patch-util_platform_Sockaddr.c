-- Include sys/socket.h before netinet/in.h on FreeBSD.
-- FreeBSD needs the sockaddr type definitions available before IPv4/IPv6
-- sockaddr structures are declared during the cjdns_sys C build.

--- util/platform/Sockaddr.c.orig	2025-12-10 17:30:44 UTC
+++ util/platform/Sockaddr.c
@@ -29,6 +29,7 @@
 #include <stdlib.h>
 #include <stddef.h>
 #include <stdint.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 
 struct Sockaddr_pvt
