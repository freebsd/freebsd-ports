--- src/drivers/driver_bsd.c.orig	2022-06-20 04:39:26.000000000 -0700
+++ src/drivers/driver_bsd.c	2022-07-03 14:14:25.865828000 -0700
@@ -14,6 +14,7 @@
 #include "driver.h"
 #include "eloop.h"
 #include "common/ieee802_11_defs.h"
+#include "common/ieee802_11_common.h"
 #include "common/wpa_common.h"
 
 #include <ifaddrs.h>
@@ -853,14 +854,18 @@
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
@@ -1197,13 +1202,41 @@
 }
 
 static int
+wpa_driver_bsd_set_rsn_wpa_ie(struct bsd_driver_data * drv,
+    struct wpa_driver_associate_params *params, const u8 *ie)
+{
+	int privacy;
+	size_t ie_len = ie[1] ? ie[1] + 2 : 0;
+
+	/* XXX error handling is wrong but unclear what to do... */
+	if (wpa_driver_bsd_set_wpa_ie(drv, ie, ie_len) < 0)
+		return -1;
+
+	privacy = !(params->pairwise_suite == WPA_CIPHER_NONE &&
+	    params->group_suite == WPA_CIPHER_NONE &&
+	    params->key_mgmt_suite == WPA_KEY_MGMT_NONE);
+	wpa_printf(MSG_DEBUG, "%s: set PRIVACY %u", __func__,
+	    privacy);
+
+	if (set80211param(drv, IEEE80211_IOC_PRIVACY, privacy) < 0)
+		return -1;
+
+	if (ie_len &&
+	    set80211param(drv, IEEE80211_IOC_WPA,
+	    ie[0] == WLAN_EID_RSN ? 2 : 1) < 0)
+		return -1;
+
+	return 0;
+}
+
+static int
 wpa_driver_bsd_associate(void *priv, struct wpa_driver_associate_params *params)
 {
 	struct bsd_driver_data *drv = priv;
 	struct ieee80211req_mlme mlme;
 	u32 mode;
-	int privacy;
 	int ret = 0;
+	const u8 *wpa_ie, *rsn_ie;
 
 	wpa_printf(MSG_DEBUG,
 		"%s: ssid '%.*s' wpa ie len %u pairwise %u group %u key mgmt %u"
@@ -1220,7 +1253,10 @@
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
@@ -1249,24 +1285,33 @@
 		ret = -1;
 	if (wpa_driver_bsd_set_auth_alg(drv, params->auth_alg) < 0)
 		ret = -1;
-	/* XXX error handling is wrong but unclear what to do... */
-	if (wpa_driver_bsd_set_wpa_ie(drv, params->wpa_ie, params->wpa_ie_len) < 0)
-		return -1;
 
-	privacy = !(params->pairwise_suite == WPA_CIPHER_NONE &&
-	    params->group_suite == WPA_CIPHER_NONE &&
-	    params->key_mgmt_suite == WPA_KEY_MGMT_NONE &&
-	    params->wpa_ie_len == 0);
-	wpa_printf(MSG_DEBUG, "%s: set PRIVACY %u", __func__, privacy);
+	if (params->wpa_ie_len) {
+		rsn_ie = get_ie(params->wpa_ie, params->wpa_ie_len,
+		    WLAN_EID_RSN);
+		if (rsn_ie) {
+			if (wpa_driver_bsd_set_rsn_wpa_ie(drv, params,
+			    rsn_ie) < 0)
+				return -1;
+		}
+		else {
+			wpa_ie = get_vendor_ie(params->wpa_ie,
+			    params->wpa_ie_len, WPA_IE_VENDOR_TYPE);
+			if (wpa_ie) {
+				if (wpa_driver_bsd_set_rsn_wpa_ie(drv, params,
+				    wpa_ie) < 0)
+					return -1;
+			}
+		}
+	}
 
-	if (set80211param(drv, IEEE80211_IOC_PRIVACY, privacy) < 0)
+	/*
+	 * NB: interface must be marked UP for association
+	 * or scanning (ap_scan=2)
+	 */
+	if (bsd_get_iface_flags(drv) < 0)
 		return -1;
 
-	if (params->wpa_ie_len &&
-	    set80211param(drv, IEEE80211_IOC_WPA,
-			  params->wpa_ie[0] == WLAN_EID_RSN ? 2 : 1) < 0)
-		return -1;
-
 	os_memset(&mlme, 0, sizeof(mlme));
 	mlme.im_op = IEEE80211_MLME_ASSOC;
 	if (params->ssid != NULL)
@@ -1485,6 +1530,17 @@
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
@@ -1493,6 +1549,7 @@
 		drv->capa.enc |= WPA_DRIVER_CAPA_ENC_TKIP;
 	if (devcaps.dc_cryptocaps & IEEE80211_CRYPTO_AES_CCM)
 		drv->capa.enc |= WPA_DRIVER_CAPA_ENC_CCMP;
+#endif
 
 	if (devcaps.dc_drivercaps & IEEE80211_C_HOSTAP)
 		drv->capa.flags |= WPA_DRIVER_FLAGS_AP;
@@ -1545,6 +1602,8 @@
 		}
 		if (ifmr.ifm_current & IFM_IEEE80211_HOSTAP)
 			return IEEE80211_M_HOSTAP;
+		if (ifmr.ifm_current & IFM_IEEE80211_IBSS)
+			return IEEE80211_M_IBSS;
 		if (ifmr.ifm_current & IFM_IEEE80211_MONITOR)
 			return IEEE80211_M_MONITOR;
 #ifdef IEEE80211_M_MBSS
