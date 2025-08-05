--- ipc-freebsd.h.orig	2024-10-01 13:02:42 UTC
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
 
@@ -389,6 +389,8 @@ static int kernel_set_device(struct wgdevice *dev)
 			nvl_aips[j] = nvlist_create(0);
 			if (!nvl_aips[j])
 				goto err_peer;
+			if (aip->flags)
+				nvlist_add_number(nvl_aips[j], "flags", aip->flags);
 			nvlist_add_number(nvl_aips[j], "cidr", aip->cidr);
 			if (aip->family == AF_INET)
 				nvlist_add_binary(nvl_aips[j], "ipv4", &aip->ip4, sizeof(aip->ip4));
