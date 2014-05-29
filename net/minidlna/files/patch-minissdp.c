--- minissdp.c.orig	2014-03-06 16:30:25.000000000 -0800
+++ minissdp.c	2014-05-29 09:34:58.763663228 -0700
@@ -60,7 +60,7 @@
 AddMulticastMembership(int s, struct lan_addr_s *iface)
 {
 	int ret;
-#ifdef HAVE_STRUCT_IP_MREQN
+#if defined(HAVE_STRUCT_IP_MREQN) && !defined(__FreeBSD__)
 	struct ip_mreqn imr;	/* Ip multicast membership */
 	/* setting up imr structure */
 	imr.imr_multiaddr.s_addr = inet_addr(SSDP_MCAST_ADDR);
