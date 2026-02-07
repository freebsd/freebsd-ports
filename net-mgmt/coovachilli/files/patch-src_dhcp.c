diff -urN src/dhcp.c.orig src/dhcp.c
--- src/dhcp.c.orig	2008-06-28 17:38:35.000000000 +0100
+++ src/dhcp.c	2008-06-29 16:17:48.000000000 +0100
@@ -625,7 +625,7 @@
 }
 
 /**
- * dhcp_se()
+ * dhcp_set()
  * Set dhcp parameters which can be altered at runtime.
  **/
 int
@@ -713,7 +713,7 @@
 int dhcp_nakDNS(struct dhcp_conn_t *conn, struct pkt_ippacket_t *pack, size_t len) {
   struct dhcp_t *this = conn->parent;
   struct pkt_udphdr_t *udph = (struct pkt_udphdr_t *)pack->payload;
-  struct dns_packet_t *dnsp = (struct dns_packet_t *)((char*)pack->payload + sizeof(struct pkt_udphdr_t));
+  /*struct dns_packet_t *dnsp = (struct dns_packet_t *)((char*)pack->payload + sizeof(struct pkt_udphdr_t));*/
   struct dns_fullpacket_t answer;
 
   memcpy(&answer, pack, len); 
@@ -1023,7 +1023,7 @@
   struct dhcp_t *this = conn->parent;
   struct pkt_tcphdr_t *tcph = (struct pkt_tcphdr_t *)pack->payload;
   struct pkt_udphdr_t *udph = (struct pkt_udphdr_t *)pack->payload;
-  size_t len = *plen;
+  /*size_t len = *plen;*/
   int i;
 
   /* Allow localhost through network... */
@@ -2592,7 +2592,7 @@
   struct pkt_ethhdr_t *ethhdr;
   
   if (this->rbuf_offset == this->rbuf_len) {
-    length = read(this->ipif.fd, this->rbuf, this->rbuf_max);
+    length = net_read(&this->ipif, this->rbuf, this->rbuf_max);
 
     if (length <= 0)
       return length;

