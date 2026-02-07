--- tcpxtract.c.orig	Sat Feb  4 23:57:57 2006
+++ tcpxtract.c	Sat Feb  4 23:58:07 2006
@@ -68,7 +68,7 @@
 
 slist_t *sessions;
 
-static uintmax_t num_packets;    /* the running total of packets */
+static uint64_t num_packets;    /* the running total of packets */
 
 enum protos {
     TCP_PROTO = 6,
