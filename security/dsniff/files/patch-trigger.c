--- ./trigger.c.orig	2001-03-15 09:33:05.000000000 +0100
+++ ./trigger.c	2014-07-22 13:20:14.000000000 +0200
@@ -276,7 +276,7 @@
 }
 	
 void
-trigger_ip(struct libnet_ip_hdr *ip)
+trigger_ip(struct libnet_ipv4_hdr *ip)
 {
 	struct trigger *t, tr;
 	u_char *buf;
@@ -305,7 +305,7 @@
 
 /* libnids needs a nids_register_udp()... */
 void
-trigger_udp(struct libnet_ip_hdr *ip)
+trigger_udp(struct libnet_ipv4_hdr *ip)
 {
 	struct trigger *t, tr;
 	struct libnet_udp_hdr *udp;
@@ -437,7 +437,7 @@
 }
 
 void
-trigger_tcp_raw(struct libnet_ip_hdr *ip)
+trigger_tcp_raw(struct libnet_ipv4_hdr *ip)
 {
 	struct trigger *t, tr;
 	struct libnet_tcp_hdr *tcp;
