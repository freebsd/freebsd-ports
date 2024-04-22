--- src/ap/hostapd.c.orig	2024-02-18 01:24:29.000000000 -0800
+++ src/ap/hostapd.c	2024-02-26 20:25:50.505205000 -0800
@@ -2029,6 +2029,20 @@
 	iface->wait_channel_update = 0;
 	iface->is_no_ir = false;
 
+#ifdef __FreeBSD
+	/* XXX hostapd_get_hw_features() is an inline that always returns -1
+	 * because MLME will not build under FreeBSD due to its use of
+	 * Linux definitions. Normally FreeBSD would uncondionally execute the
+	 * "Not all drivers support..." block. Instead we #ifdef out the entire
+	 * block of code instead of maintaining the fallacy that
+	 * hostapd_get_hw_features() returns anything meaninful.
+	 *
+	 * Ideally WANT_AP_MLME should be taught about FreeBSD data structures
+	 * and defintions. Instead we do this to enable channel selection in
+	 * hostapd.conf.
+	 */
+	iface->freq = iface->conf->channel;
+#else
 	if (hostapd_get_hw_features(iface)) {
 		/* Not all drivers support this yet, so continue without hw
 		 * feature data. */
@@ -2080,6 +2094,7 @@
 		if (iface->conf->ieee80211h)
 			wpa_printf(MSG_DEBUG, "DFS support is enabled");
 	}
+#endif
 	return hostapd_setup_interface_complete(iface, 0);
 
 fail:
