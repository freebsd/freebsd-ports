--- minissdp.c.orig	2015-09-10 19:24:09 UTC
+++ minissdp.c
@@ -60,7 +60,7 @@ static int
 AddMulticastMembership(int s, struct lan_addr_s *iface)
 {
 	int ret;
-#ifdef HAVE_STRUCT_IP_MREQN
+#if defined(HAVE_STRUCT_IP_MREQN) && !defined(__FreeBSD__)
 	struct ip_mreqn imr;	/* Ip multicast membership */
 	/* setting up imr structure */
 	memset(&imr, '\0', sizeof(imr));
@@ -117,7 +117,11 @@ OpenAndConfSSDPReceiveSocket(void)
 	 * to receive datagramms send to this multicast address.
 	 * To specify the local nics we want to use we have to use setsockopt,
 	 * see AddMulticastMembership(...). */
+#ifdef __FreeBSD__
+	sockname.sin_addr.s_addr = htonl(INADDR_ANY);
+#else
 	sockname.sin_addr.s_addr = inet_addr(SSDP_MCAST_ADDR);
+#endif
 
 	if (bind(s, (struct sockaddr *)&sockname, sizeof(struct sockaddr_in)) < 0)
 	{
