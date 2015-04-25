--- src/p2p/p2p.c.orig	2015-04-24 22:44:26 UTC
+++ src/p2p/p2p.c
@@ -778,6 +778,7 @@ int p2p_add_device(struct p2p_data *p2p,
 	if (os_memcmp(addr, p2p_dev_addr, ETH_ALEN) != 0)
 		os_memcpy(dev->interface_addr, addr, ETH_ALEN);
 	if (msg.ssid &&
+	    msg.ssid[1] <= sizeof(dev->oper_ssid) &&
 	    (msg.ssid[1] != P2P_WILDCARD_SSID_LEN ||
 	     os_memcmp(msg.ssid + 2, P2P_WILDCARD_SSID, P2P_WILDCARD_SSID_LEN)
 	     != 0)) {
