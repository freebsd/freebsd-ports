--- ./trigger.h.orig	2001-03-15 09:33:06.000000000 +0100
+++ ./trigger.h	2014-07-22 13:20:14.000000000 +0200
@@ -24,10 +24,10 @@
 int	trigger_set_tcp(int port, char *name);
 int	trigger_set_rpc(int program, char *name);
 
-void	trigger_ip(struct libnet_ip_hdr *ip);
-void	trigger_udp(struct libnet_ip_hdr *ip);
+void	trigger_ip(struct libnet_ipv4_hdr *ip);
+void	trigger_udp(struct libnet_ipv4_hdr *ip);
 void	trigger_tcp(struct tcp_stream *ts, void **conn_save);
-void	trigger_tcp_raw(struct libnet_ip_hdr *ip);
+void	trigger_tcp_raw(struct libnet_ipv4_hdr *ip);
 void	trigger_tcp_raw_timeout(int signal);
 void	trigger_rpc(int program, int proto, int port);
 
