--- ./tcp_raw.h.orig	2001-03-15 09:33:06.000000000 +0100
+++ ./tcp_raw.h	2014-07-22 13:20:14.000000000 +0200
@@ -15,7 +15,7 @@
 				   u_short sport, u_short dport,
 				   u_char *buf, int len);
 
-struct iovec   *tcp_raw_input(struct libnet_ip_hdr *ip,
+struct iovec   *tcp_raw_input(struct libnet_ipv4_hdr *ip,
 			      struct libnet_tcp_hdr *tcp, int len);
 
 void		tcp_raw_timeout(int timeout, tcp_raw_callback_t callback);
