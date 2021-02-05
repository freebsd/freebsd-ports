--- interface.c.orig	2020-12-29 09:42:21 UTC
+++ interface.c
@@ -61,6 +61,8 @@ void touch_iface(struct Interface *iface)
 
 int setup_iface(int sock, struct Interface *iface)
 {
+	int was_ready = iface->state_info.ready;
+
 	iface->state_info.changed = 0;
 	iface->state_info.ready = 0;
 
@@ -97,8 +99,11 @@ int setup_iface(int sock, struct Interface *iface)
 		return -1;
 	}
 
+	iface->state_info.ready = was_ready;
+
 	/* join the allrouters multicast group so we get the solicitations */
 	if (setup_allrouters_membership(sock, iface) < 0) {
+		iface->state_info.ready = 0;
 		return -1;
 	}
 
