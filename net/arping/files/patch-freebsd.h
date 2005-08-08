--- freebsd.h.orig	Mon Aug  8 07:22:04 2005
+++ freebsd.h	Mon Aug  8 07:22:35 2005
@@ -11,7 +11,7 @@
 	__u16 h_proto;/* packet type ID field*/
 };
 
-struct icmphdr {
+struct icmphdr_ {
 	__u8 type;
 	__u8 code;
 	__u16 checksum;
