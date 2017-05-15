--- device-bsd44.c.orig	2015-11-19 13:58:52 UTC
+++ device-bsd44.c
@@ -116,6 +116,24 @@ int update_device_info(int sock, struct 
 
 int setup_allrouters_membership(int sock, struct Interface *iface)
 {
+	struct ipv6_mreq mreq;
+
+	memset(&mreq, 0, sizeof(mreq));
+	mreq.ipv6mr_interface = iface->props.if_index;
+
+	/* all-routers multicast address */
+	if (inet_pton(AF_INET6, "ff02::2",
+			&mreq.ipv6mr_multiaddr.s6_addr) != 1) {
+		flog(LOG_ERR, "inet_pton failed");
+		return (-1);
+	}
+
+	if (setsockopt(sock, IPPROTO_IPV6, IPV6_JOIN_GROUP,
+			&mreq, sizeof(mreq)) < 0) {
+		flog(LOG_ERR, "can't join ipv6-allrouters on %s", iface->props.name);
+		return (-1);
+	}
+
 	return 0;
 }
 
