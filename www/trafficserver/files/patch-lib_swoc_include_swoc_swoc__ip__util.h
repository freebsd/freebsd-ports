--- lib/swoc/include/swoc/swoc_ip_util.h.orig	2026-10-20 03:01:58 UTC
+++ lib/swoc/include/swoc/swoc_ip_util.h
@@ -93,12 +93,12 @@ inline bool is_loopback_network_order(in_addr_t addr) 
   return is_loopback_host_order(addr);
 }
 
-inline bool is_link_local_network_order(inaddr_t addr) {
+inline bool is_link_local_network_order(in_addr_t addr) {
   return is_link_local_host_order(addr);
 }
 
 inline bool is_private_network_order(in_addr_t addr) {
-  return is_link_local_host_order(addr);
+  return is_private_host_order(addr);
 }
 
 inline bool is_multicast_network_order(in_addr_t addr) {
