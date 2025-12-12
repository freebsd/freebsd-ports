--- ipc-freebsd.h.orig	2025-09-03 14:11:13 UTC
+++ ipc-freebsd.h
@@ -15,13 +15,13 @@ static int get_dgram_socket(void)
 {
 	static int sock = -1;
 	if (sock < 0)
-		sock = socket(AF_INET, SOCK_DGRAM, 0);
+		sock = socket(AF_LOCAL, SOCK_DGRAM, 0);
 	return sock;
 }
 
 static int kernel_get_wireguard_interfaces(struct string_list *list)
 {
-	struct ifgroupreq ifgr = { .ifgr_name = "wg" };
+	struct ifgroupreq ifgr = { .ifgr_name = "amn" };
 	struct ifg_req *ifg;
 	int s = get_dgram_socket(), ret = 0;
 
@@ -458,15 +458,15 @@ static int kernel_set_device(struct wgdevice *dev)
 	if (dev->flags & WGDEVICE_HAS_H4)
 		nvlist_add_binary(nvl_device, "h4", dev->transport_packet_magic_header, strlen(dev->transport_packet_magic_header) + 1);
 	if (dev->flags & WGDEVICE_HAS_I1)
-		nvlist_add_binary(nvl_device, "i1", dev->i1, strlen(dev->i1) + 1);
+		nvlist_add_binary(nvl_device, "i1", dev->i1 ? dev->i1 : "", strlen(dev->i1 ? dev->i1 : "") + 1);
 	if (dev->flags & WGDEVICE_HAS_I2)
-		nvlist_add_binary(nvl_device, "i2", dev->i2, strlen(dev->i2) + 1);
+		nvlist_add_binary(nvl_device, "i2", dev->i2 ? dev->i2 : "", strlen(dev->i2 ? dev->i2 : "") + 1);
 	if (dev->flags & WGDEVICE_HAS_I3)
-		nvlist_add_binary(nvl_device, "i3", dev->i3, strlen(dev->i3) + 1);
+		nvlist_add_binary(nvl_device, "i3", dev->i3 ? dev->i3 : "", strlen(dev->i3 ? dev->i3 : "") + 1);
 	if (dev->flags & WGDEVICE_HAS_I4)
-		nvlist_add_binary(nvl_device, "i4", dev->i4, strlen(dev->i4) + 1);
+		nvlist_add_binary(nvl_device, "i4", dev->i4 ? dev->i4 : "", strlen(dev->i4 ? dev->i4 : "") + 1);
 	if (dev->flags & WGDEVICE_HAS_I5)
-		nvlist_add_binary(nvl_device, "i5", dev->i5, strlen(dev->i5) + 1);
+		nvlist_add_binary(nvl_device, "i5", dev->i5 ? dev->i5 : "", strlen(dev->i5 ? dev->i5 : "") + 1);
 	if (dev->flags & WGDEVICE_HAS_FWMARK)
 		nvlist_add_number(nvl_device, "user-cookie", dev->fwmark);
 	if (dev->flags & WGDEVICE_REPLACE_PEERS)
@@ -502,6 +502,8 @@ static int kernel_set_device(struct wgdevice *dev)
 			nvl_aips[j] = nvlist_create(0);
 			if (!nvl_aips[j])
 				goto err_peer;
+			if (aip->flags)
+				nvlist_add_number(nvl_aips[j], "flags", aip->flags);
 			nvlist_add_number(nvl_aips[j], "cidr", aip->cidr);
 			if (aip->family == AF_INET)
 				nvlist_add_binary(nvl_aips[j], "ipv4", &aip->ip4, sizeof(aip->ip4));
