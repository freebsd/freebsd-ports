--- dhcpclient.c.orig	Thu Apr 14 16:07:26 2005
+++ dhcpclient.c	Thu Apr 14 15:24:19 2005
@@ -236,8 +236,8 @@
 {
 	struct dhcpclient_req *req = tmpl->dhcp_req;
 	struct dhcp_msg *msg = (struct dhcp_msg *)buf;
-	size_t optlen = buflen - sizeof(*msg);
-	uint8_t *p, *end, opt1, opt1len, *opt1p;
+	size_t optlen = buflen - sizeof(*msg), opt1len;
+	uint8_t *p, *end, opt1, *opt1p;
 	short replyreq = 0, ack = 0, done = 0;
 	struct netconf nc;
 	struct addr *which = NULL, ipmask;
@@ -472,7 +472,8 @@
 
 	memset(buf, 0, sizeof(buf));
 
-	eth = (struct eth_hdr *)p = buf;
+	p = buf;
+	eth = (struct eth_hdr *)p;
 	eth_pack_hdr(eth, ETH_ADDR_BROADCAST, req->ea, ETH_TYPE_IP);
 
 	restlen -= ETH_HDR_LEN;
@@ -524,7 +525,8 @@
 
 	memset(buf, 0, sizeof(buf));
 
-	eth = (struct eth_hdr *)p = buf;
+	p = buf;
+	eth = (struct eth_hdr *)p;
 	eth_pack_hdr(eth, req->server_ea, req->ea, ETH_TYPE_IP);
 
 	restlen -= ETH_HDR_LEN;
