--- src/drivers/driver_bsd.c.orig	2024-07-20 11:04:37.000000000 -0700
+++ src/drivers/driver_bsd.c	2024-09-13 15:39:20.543245000 -0700
@@ -14,6 +14,7 @@
 #include "driver.h"
 #include "eloop.h"
 #include "common/ieee802_11_defs.h"
+#include "common/ieee802_11_common.h"
 #include "common/wpa_common.h"
 
 #include <ifaddrs.h>
@@ -293,8 +294,9 @@
 }
 
 static int
-bsd_get_iface_flags(struct bsd_driver_data *drv)
+bsd_ctrl_iface(void *priv, int enable)
 {
+	struct bsd_driver_data *drv = priv;
 	struct ifreq ifr;
 
 	os_memset(&ifr, 0, sizeof(ifr));
@@ -302,10 +304,37 @@
 
 	if (ioctl(drv->global->sock, SIOCGIFFLAGS, &ifr) < 0) {
 		wpa_printf(MSG_ERROR, "ioctl[SIOCGIFFLAGS]: %s",
+			   strerror(errno));
+		return -1;
+	}
+	drv->flags = ifr.ifr_flags;
+
+
+	if (enable) {
+		if (ifr.ifr_flags & IFF_UP)
+			goto nochange;
+		ifr.ifr_flags |= IFF_UP;
+	} else {
+		if (!(ifr.ifr_flags & IFF_UP))
+			goto nochange;
+		ifr.ifr_flags &= ~IFF_UP;
+	}
+
+	if (ioctl(drv->global->sock, SIOCSIFFLAGS, &ifr) < 0) {
+		wpa_printf(MSG_ERROR, "ioctl[SIOCSIFFLAGS]: %s",
 			   strerror(errno));
 		return -1;
 	}
+
+	wpa_printf(MSG_DEBUG, "%s: if %s (changed) enable %d IFF_UP %d ",
+	    __func__, drv->ifname, enable, ((ifr.ifr_flags & IFF_UP) != 0));
+
 	drv->flags = ifr.ifr_flags;
+	return 0;
+
+nochange:
+	wpa_printf(MSG_DEBUG, "%s: if %s (no change) enable %d IFF_UP %d ",
+	    __func__, drv->ifname, enable, ((ifr.ifr_flags & IFF_UP) != 0));
 	return 0;
 }
 
@@ -525,7 +554,7 @@
 			   __func__);
 		return -1;
 	}
-	return 0;
+	return bsd_ctrl_iface(priv, 1);
 }
 
 static void
@@ -853,14 +882,18 @@
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
@@ -1027,7 +1060,8 @@
 	if (l2_packet_get_own_addr(drv->sock_xmit, params->own_addr))
 		goto bad;
 
-	if (bsd_get_iface_flags(drv) < 0)
+	/* mark down during setup */
+	if (bsd_ctrl_iface(drv, 0) < 0)
 		goto bad;
 
 	if (bsd_set_mediaopt(drv, IFM_OMASK, IFM_IEEE80211_HOSTAP) < 0) {
@@ -1052,12 +1086,13 @@
 {
 	struct bsd_driver_data *drv = priv;
 
+	if (drv->ifindex != 0)
+		bsd_ctrl_iface(drv, 0);
 	if (drv->sock_xmit != NULL)
 		l2_packet_deinit(drv->sock_xmit);
 	os_free(drv);
 }
 
-
 static int
 bsd_set_sta_authorized(void *priv, const u8 *addr,
 		       unsigned int total_flags, unsigned int flags_or,
@@ -1199,13 +1234,41 @@
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
@@ -1222,7 +1285,10 @@
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
@@ -1251,22 +1317,31 @@
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
-
-	if (set80211param(drv, IEEE80211_IOC_PRIVACY, privacy) < 0)
-		return -1;
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
 
-	if (params->wpa_ie_len &&
-	    set80211param(drv, IEEE80211_IOC_WPA,
-			  params->wpa_ie[0] == WLAN_EID_RSN ? 2 : 1) < 0)
+	/*
+	 * NB: interface must be marked UP for association
+	 * or scanning (ap_scan=2)
+	 */
+	if (bsd_ctrl_iface(drv, 1) < 0)
 		return -1;
 
 	os_memset(&mlme, 0, sizeof(mlme));
@@ -1311,11 +1386,8 @@
 	}
 
 	/* NB: interface must be marked UP to do a scan */
-	if (!(drv->flags & IFF_UP)) {
-		wpa_printf(MSG_DEBUG, "%s: interface is not up, cannot scan",
-			   __func__);
+	if (bsd_ctrl_iface(drv, 1) < 0)
 		return -1;
-	}
 
 #ifdef IEEE80211_IOC_SCAN_MAX_SSID
 	os_memset(&sr, 0, sizeof(sr));
@@ -1547,6 +1619,8 @@
 		}
 		if (ifmr.ifm_current & IFM_IEEE80211_HOSTAP)
 			return IEEE80211_M_HOSTAP;
+		if (ifmr.ifm_current & IFM_IEEE80211_IBSS)
+			return IEEE80211_M_IBSS;
 		if (ifmr.ifm_current & IFM_IEEE80211_MONITOR)
 			return IEEE80211_M_MONITOR;
 #ifdef IEEE80211_M_MBSS
@@ -1607,7 +1681,7 @@
 		drv->capa.key_mgmt_iftype[i] = drv->capa.key_mgmt;
 
 	/* Down interface during setup. */
-	if (bsd_get_iface_flags(drv) < 0)
+	if (bsd_ctrl_iface(drv, 0) < 0)
 		goto fail;
 
 	/* Proven to work, lets go! */
@@ -1631,6 +1705,9 @@
 	if (drv->ifindex != 0 && !drv->if_removed) {
 		wpa_driver_bsd_set_wpa(drv, 0);
 
+		/* NB: mark interface down */
+		bsd_ctrl_iface(drv, 0);
+
 		wpa_driver_bsd_set_wpa_internal(drv, drv->prev_wpa,
 						drv->prev_privacy);
 
