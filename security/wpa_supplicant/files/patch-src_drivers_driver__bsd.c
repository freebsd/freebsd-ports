--- src/drivers/driver_bsd.c.orig	2021-06-02 14:11:18.000000000 -0700
+++ src/drivers/driver_bsd.c	2021-06-13 23:08:54.275496000 -0700
@@ -853,14 +853,18 @@
 		drv = bsd_get_drvindex(global, ifm->ifm_index);
 		if (drv == NULL)
 			return;
-		if ((ifm->ifm_flags & IFF_UP) == 0 &&
-		    (drv->flags & IFF_UP) != 0) {
+		if (((ifm->ifm_flags & IFF_UP) == 0 ||
+		    (ifm->ifm_flags & IFF_RUNNING) == 0) &&
+		    (drv->flags & IFF_UP) != 0 &&
+		    (drv->flags & IFF_RUNNING) != 0) {
 			wpa_printf(MSG_DEBUG, "RTM_IFINFO: Interface '%s' DOWN",
 				   drv->ifname);
 			wpa_supplicant_event(drv->ctx, EVENT_INTERFACE_DISABLED,
 					     NULL);
 		} else if ((ifm->ifm_flags & IFF_UP) != 0 &&
-		    (drv->flags & IFF_UP) == 0) {
+		    (ifm->ifm_flags & IFF_RUNNING) != 0 &&
+		    ((drv->flags & IFF_UP) == 0 ||
+		    (drv->flags & IFF_RUNNING)  == 0)) {
 			wpa_printf(MSG_DEBUG, "RTM_IFINFO: Interface '%s' UP",
 				   drv->ifname);
