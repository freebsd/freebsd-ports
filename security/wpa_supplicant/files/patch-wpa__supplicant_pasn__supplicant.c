--- wpa_supplicant/pasn_supplicant.c.orig	2021-04-10 02:48:08.000000000 -0700
+++ wpa_supplicant/pasn_supplicant.c	2021-04-12 10:44:14.939212000 -0700
@@ -1079,7 +1079,11 @@
 	pasn->group = group;
 	pasn->freq = freq;
 
+#ifdef CONFIG_TESTING_OPTIONS
 	if (wpa_s->conf->force_kdk_derivation ||
+#else
+	if (
+#endif
 	    (wpa_s->drv_flags2 & WPA_DRIVER_FLAGS2_SEC_LTF &&
 	     ieee802_11_rsnx_capab(beacon_rsnxe, WLAN_RSNX_CAPAB_SECURE_LTF)))
 		pasn->kdk_len = WPA_KDK_MAX_LEN;
