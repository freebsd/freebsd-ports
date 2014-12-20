--- include/ntp_net.h.orig	2014-12-19 03:56:52.000000000 -0800
+++ include/ntp_net.h	2014-12-19 16:21:51.050264459 -0800
@@ -5,6 +5,11 @@
 #ifndef NTP_NET_H
 #define NTP_NET_H
 
+/* XXX obtained from /usr/include/netinet6/in6.h */
+#define s6_addr8  __u6_addr.__u6_addr8
+#define s6_addr16 __u6_addr.__u6_addr16
+#define s6_addr32 __u6_addr.__u6_addr32
+
 #include <sys/types.h>
 #ifdef HAVE_SYS_SOCKET_H
 #include <sys/socket.h>
@@ -29,6 +34,13 @@
 	struct sockaddr		sa;
 	struct sockaddr_in	sa4;
 	struct sockaddr_in6	sa6;
+/* XXX obtained from /usr/include/netinet6/in6.h */
+	union {
+		uint8_t         __u6_addr8[16];
+		uint16_t        __u6_addr16[8];
+		uint32_t        __u6_addr32[4];
+	} __u6_addr;                    /* 128-bit IP6 address */
+
 } sockaddr_u;
 
 /*
