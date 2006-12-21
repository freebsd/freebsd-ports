
$FreeBSD$

--- utils.h.orig
+++ utils.h
@@ -36,7 +36,7 @@
 #define ETHERNET_SIZE 14 /* ethernet headers are 14 bytes */
 #define IPV6_SIZE 40 /* ipv6 headers without fragment ... are 40 bytes */
 #define ICMP6_HEADER_SIZE 8
-#define ETHERTYPE_IPV6 0x86dd
+/*#define ETHERTYPE_IPV6 0x86dd */
 
 /*Size to build char* address in a readable form*/
 #define IP6_STR_SIZE 40 /*xxxx:xxxx:xxx:xxxx:xxxx:xxxx:xxxx:xxxx*/
