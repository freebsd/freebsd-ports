- workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=264625

--- src/nemesis-proto_igmp.c.orig	2022-06-12 06:55:58 UTC
+++ src/nemesis-proto_igmp.c
@@ -6,6 +6,8 @@
  * nemesis-proto_igmp.c (IGMP Packet Generator)
  */
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
 #include <netinet/if_ether.h>
 
