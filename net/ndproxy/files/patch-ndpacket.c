--- ndpacket.c.orig	2019-02-19 09:46:15 UTC
+++ ndpacket.c
@@ -59,6 +59,12 @@
 
 // called by pfil_run_hooks() @ ip6_input.c:ip_input()
 
+#if __FreeBSD_version < 1400000
+static uint8_t if_getaddrlen(if_t ifp) {
+	return (ifp->if_addrlen);
+}
+#endif
+
 #ifdef PFIL_VERSION
 pfil_return_t packet(struct mbuf **packet_mp, struct ifnet *packet_ifnet,
                      const int packet_dir, void *packet_arg, struct inpcb *packet_inpcb) {
@@ -183,7 +189,7 @@ int packet(void *packet_arg, struct mbuf **packet_mp, 
   // create a new mbuf to send a neighbor advertisement
   // ICMPv6 options are rounded up to 8 bytes alignment
   maxlen = (sizeof(struct ip6_hdr) + sizeof(struct nd_neighbor_advert) +
-	    sizeof(struct nd_opt_hdr) + packet_ifnet->if_addrlen + 7) & ~7;
+	    sizeof(struct nd_opt_hdr) + if_getaddrlen(packet_ifnet) + 7) & ~7;
   if (max_linkhdr + maxlen > MCLBYTES) {
     printf("NDPROXY ERROR: reply length > MCLBYTES\n");
     return 0;
@@ -203,7 +209,7 @@ int packet(void *packet_arg, struct mbuf **packet_mp, 
   // packet content:
   // IPv6 header + ICMPv6 Neighbor Advertisement including target address + target link-layer ICMPv6 address option
   mreply->m_pkthdr.len = mreply->m_len = (sizeof(struct ip6_hdr) + sizeof(struct nd_neighbor_advert)
-					  + sizeof(struct nd_opt_hdr) + packet_ifnet->if_addrlen + 7) & ~7;
+					  + sizeof(struct nd_opt_hdr) + if_getaddrlen(packet_ifnet) + 7) & ~7;
 
   // reserve space for the link-layer header
   mreply->m_data += max_linkhdr;
