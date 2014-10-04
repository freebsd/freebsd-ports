# $FreeBSD$
--- vrrp_network.c.orig	2014-05-04 01:27:14.212855362 +0200
+++ vrrp_network.c	2014-05-04 01:27:50.289959806 +0200
@@ -113,7 +113,7 @@
 	 iph->ip_hl = 5;
 	 iph->ip_v = 4;
 	 iph->ip_tos = 0;
-#if defined(__FreeBSD__) || defined(__NetBSD__)
+#if (defined(__FreeBSD__) && (__FreeBSD_version < 1100030)) || defined(__NetBSD__)
 	 iph->ip_len = sizeof(struct ip) + vrrp_network_vrrphdr_len(vr) + vrrp_ah_ahhdr_len(vr);
 #else
 	 iph->ip_len = htons(sizeof(struct ip) + vrrp_network_vrrphdr_len(vr) + vrrp_ah_ahhdr_len(vr));
