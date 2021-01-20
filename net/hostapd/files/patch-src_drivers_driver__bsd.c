--- src/drivers/driver_bsd.c.orig	2019-08-07 06:25:25.000000000 -0700
+++ src/drivers/driver_bsd.c	2021-01-20 08:04:07.589603000 -0800
@@ -649,7 +649,7 @@
 		len = 2048;
 	}
 
-	return len;
+	return (len == 0) ? 2048 : len;
 }
 
 #ifdef HOSTAPD
@@ -665,7 +665,11 @@
 static int bsd_sta_deauth(void *priv, const u8 *own_addr, const u8 *addr,
 			  u16 reason_code);
 
+#ifdef __DragonFly__
+const char *
+#else
 static const char *
+#endif
 ether_sprintf(const u8 *addr)
 {
 	static char buf[sizeof(MACSTR)];
@@ -1336,14 +1340,18 @@
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
 			wpa_supplicant_event(drv->ctx, EVENT_INTERFACE_ENABLED,
