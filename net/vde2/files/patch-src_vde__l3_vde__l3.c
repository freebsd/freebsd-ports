--- src/vde_l3/vde_l3.c.orig	2021-02-23 10:35:14 UTC
+++ src/vde_l3/vde_l3.c
@@ -99,17 +99,19 @@ struct routing_policy unlimited_fifo_routing_policy ={
 	.policy_init = ufifo_init
 };
 
-
+static
 inline struct vde_ethernet_header *ethhead(struct vde_buff *vdb)
 {
 	return (struct vde_ethernet_header*)(vdb->data);
 }
 
+static
 inline struct iphdr *iphead(struct vde_buff *vdb)
 {
 	return (struct iphdr*)(vdb->data + 14);
 }
 
+static
 inline void *payload(struct vde_buff *vdb)
 {
 	return (uint8_t*)(vdb->data + 14 + sizeof(struct iphdr));
