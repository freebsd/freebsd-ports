--- ipc-freebsd.h.orig	2025-07-22 19:01:39 UTC
+++ ipc-freebsd.h
@@ -21,7 +21,7 @@ static int kernel_get_wireguard_interfaces(struct stri
 
 static int kernel_get_wireguard_interfaces(struct string_list *list)
 {
-	struct ifgroupreq ifgr = { .ifgr_name = "wg" };
+	struct ifgroupreq ifgr = { .ifgr_name = "awg" };
 	struct ifg_req *ifg;
 	int s = get_dgram_socket(), ret = 0;
 
