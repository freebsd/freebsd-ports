--- arping.c.orig	Mon Aug  8 07:21:57 2005
+++ arping.c	Mon Aug  8 07:22:23 2005
@@ -258,7 +258,7 @@
 	struct ethhdr *eth;
 	struct arphdr *harp;
 	struct iphdr *hip;
-	struct icmphdr *hicmp;
+	struct icmphdr_ *hicmp;
 	unsigned int c;
 	unsigned char *cp;
 	struct timeval recvtime;
@@ -276,7 +276,7 @@
 		// ping mac
 		hip = (struct iphdr*)((char*)eth
 				      + sizeof(struct libnet_ethernet_hdr));
-		hicmp = (struct icmphdr*)((char*)hip + sizeof(struct iphdr));
+		hicmp = (struct icmphdr_*)((char*)hip + sizeof(struct iphdr));
 		if ((htons(hicmp->type) == ICMP_ECHOREPLY)
 		    && ((!memcmp(eth->h_source, eth_target, ETH_ALEN)
 			 || !memcmp(eth_target, eth_xmas, ETH_ALEN)))
