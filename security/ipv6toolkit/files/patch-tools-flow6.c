--- tools/flow6.c.orig	2015-04-05 14:00:06 UTC
+++ tools/flow6.c
@@ -86,7 +86,7 @@ unsigned int		pktbytes;
 bpf_u_int32			my_netmask;
 bpf_u_int32			my_ip;
 struct bpf_program	pcap_filter;
-char 				dev[64], errbuf[PCAP_ERRBUF_SIZE];
+char 				dev[64];
 unsigned char		buffer[65556], buffrh[MIN_IPV6_HLEN + MIN_TCP_HLEN];
 unsigned char		*v6buffer, *ptr, *startofprefixes;
 char				*pref;
