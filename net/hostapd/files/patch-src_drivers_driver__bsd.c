--- src/drivers/driver_bsd.c.orig	2022-01-16 12:51:29.000000000 -0800
+++ src/drivers/driver_bsd.c	2022-06-20 07:14:50.617305000 -0700
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
 			wpa_supplicant_event(drv->ctx, EVENT_INTERFACE_ENABLED,
@@ -1220,7 +1224,10 @@
 		mode = 0 /* STA */;
 		break;
 	case IEEE80211_MODE_IBSS:
+#if 0
 		mode = IFM_IEEE80211_IBSS;
+#endif
+		mode = IFM_IEEE80211_ADHOC;
 		break;
 	case IEEE80211_MODE_AP:
 		mode = IFM_IEEE80211_HOSTAP;
@@ -1267,6 +1274,13 @@
 			  params->wpa_ie[0] == WLAN_EID_RSN ? 2 : 1) < 0)
 		return -1;
 
+	/*
+	 * NB: interface must be marked UP for association
+	 * or scanning (ap_scan=2)
+	 */
+	if (bsd_get_iface_flags(drv) < 0)
+		return -1;
+
 	os_memset(&mlme, 0, sizeof(mlme));
 	mlme.im_op = IEEE80211_MLME_ASSOC;
 	if (params->ssid != NULL)
@@ -1485,6 +1499,17 @@
 	if (devcaps.dc_drivercaps & IEEE80211_C_WPA2)
 		drv->capa.key_mgmt = WPA_DRIVER_CAPA_KEY_MGMT_WPA2 |
 			WPA_DRIVER_CAPA_KEY_MGMT_WPA2_PSK;
+#ifdef __FreeBSD__
+	drv->capa.enc |= WPA_DRIVER_CAPA_ENC_WEP40 |
+	    WPA_DRIVER_CAPA_ENC_WEP104 |
+	    WPA_DRIVER_CAPA_ENC_TKIP |
+	    WPA_DRIVER_CAPA_ENC_CCMP;
+#else
+	/*
+	 * XXX
+	 * FreeBSD exports hardware cryptocaps.  These have no meaning for wpa
+	 * since net80211 performs software crypto.
+	 */
 
 	if (devcaps.dc_cryptocaps & IEEE80211_CRYPTO_WEP)
 		drv->capa.enc |= WPA_DRIVER_CAPA_ENC_WEP40 |
@@ -1493,6 +1518,7 @@
 		drv->capa.enc |= WPA_DRIVER_CAPA_ENC_TKIP;
 	if (devcaps.dc_cryptocaps & IEEE80211_CRYPTO_AES_CCM)
 		drv->capa.enc |= WPA_DRIVER_CAPA_ENC_CCMP;
+#endif
 
 	if (devcaps.dc_drivercaps & IEEE80211_C_HOSTAP)
 		drv->capa.flags |= WPA_DRIVER_FLAGS_AP;
@@ -1545,6 +1571,8 @@
 		}
 		if (ifmr.ifm_current & IFM_IEEE80211_HOSTAP)
 			return IEEE80211_M_HOSTAP;
+		if (ifmr.ifm_current & IFM_IEEE80211_IBSS)
+			return IEEE80211_M_IBSS;
 		if (ifmr.ifm_current & IFM_IEEE80211_MONITOR)
 			return IEEE80211_M_MONITOR;
 #ifdef IEEE80211_M_MBSS
