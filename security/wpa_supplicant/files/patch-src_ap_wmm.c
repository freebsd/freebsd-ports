--- src/ap/wmm.c.orig	2015-03-15 17:30:39 UTC
+++ src/ap/wmm.c
@@ -274,6 +274,9 @@ void hostapd_wmm_action(struct hostapd_d
 		return;
 	}
 
+	if (left < 0)
+		return; /* not a valid WMM Action frame */
+
 	/* extract the tspec info element */
 	if (ieee802_11_parse_elems(pos, left, &elems, 1) == ParseFailed) {
 		hostapd_logger(hapd, mgmt->sa, HOSTAPD_MODULE_IEEE80211,
