--- ./tcp_raw.c.orig	2001-03-15 09:33:04.000000000 +0100
+++ ./tcp_raw.c	2014-07-22 13:20:14.000000000 +0200
@@ -119,7 +119,7 @@
 }
 
 struct iovec *
-tcp_raw_input(struct libnet_ip_hdr *ip, struct libnet_tcp_hdr *tcp, int len)
+tcp_raw_input(struct libnet_ipv4_hdr *ip, struct libnet_tcp_hdr *tcp, int len)
 {
 	struct tha tha;
 	struct tcp_conn *conn;
@@ -131,7 +131,7 @@
 
 	/* Verify TCP checksum. */
 	cksum = tcp->th_sum;
-	libnet_do_checksum((u_char *) ip, IPPROTO_TCP, len);
+	libnet_do_checksum(NULL, (u_char *) ip, IPPROTO_TCP, len);
 
 	if (cksum != tcp->th_sum)
 		return (NULL);
