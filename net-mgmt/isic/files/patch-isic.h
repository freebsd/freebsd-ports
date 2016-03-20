--- isic.h.orig	2006-12-16 00:08:44 UTC
+++ isic.h
@@ -6,10 +6,13 @@
 
 #include <libnet.h>
 
+#include <netinet/ip.h>
 #include <netinet/ip_icmp.h>
 #include <netinet/icmp6.h>
 #include <netinet/ip6.h>
 #include <netinet/if_ether.h>
+#include <netinet/udp.h>
+#include <netinet/tcp.h>
 
 #ifndef ETHER_FRAME_SIZE
 #define ETHER_FRAME_SIZE 1500
@@ -21,11 +24,6 @@
 #define IP6_FRAGH 8
 #define ICMP6_H   8
 
-/* We want a random function that returns 0 to 0x7fff */
-#if ( RAND_MAX != 2147483647 )  /* expect signed long */
-#error Random IP generation broken: unexpected RAND_MAX.
-#endif
-
 #define RAND8  ((u_int8_t)(rand() & 0xff))
 #define RAND16 ((u_int16_t)(rand() & 0xffff))
 #define RAND32 ((u_int32_t)((RAND16 << 16) + RAND16))
