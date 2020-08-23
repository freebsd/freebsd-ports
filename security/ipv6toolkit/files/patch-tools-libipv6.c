--- tools/libipv6.c.orig	2015-04-05 14:01:29 UTC
+++ tools/libipv6.c
@@ -70,8 +70,8 @@ sigjmp_buf			env;
 unsigned int		canjump;
 
 /* pcap variables */
-char				errbuf[PCAP_ERRBUF_SIZE];
-struct bpf_program	pcap_filter;
+static char				errbuf[PCAP_ERRBUF_SIZE];
+static struct bpf_program	pcap_filter;
 
 #ifdef __linux__
 /* Netlink requests */
