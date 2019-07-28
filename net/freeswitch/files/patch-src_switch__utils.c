--- src/switch_utils.c.orig	2019-05-26 01:06:48 UTC
+++ src/switch_utils.c
@@ -1847,7 +1847,7 @@ SWITCH_DECLARE(switch_status_t) switch_f
 				goto doh;
 			}
 
-			switch_copy_string(buf, get_addr(abuf, sizeof(abuf), (struct sockaddr *) &iface_out, sizeof(struct sockaddr_storage)), len);
+			switch_copy_string(buf, get_addr(abuf, sizeof(abuf), (struct sockaddr *) &iface_out, sizeof(iface_out)), len);
 			if (mask) {
 				get_netmask((struct sockaddr_in *) &iface_out, mask);
 			}
