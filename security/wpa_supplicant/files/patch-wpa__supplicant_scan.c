--- wpa_supplicant/scan.c.orig	2014-10-09 14:41:31 UTC
+++ wpa_supplicant/scan.c
@@ -1548,7 +1548,7 @@ struct wpabuf * wpa_scan_get_vendor_ie_m
 static int wpa_scan_result_compar(const void *a, const void *b)
 {
 #define IS_5GHZ(n) (n > 4000)
-#define MIN(a,b) a < b ? a : b
+#define MINAB(a,b) a < b ? a : b
 	struct wpa_scan_res **_wa = (void *) a;
 	struct wpa_scan_res **_wb = (void *) b;
 	struct wpa_scan_res *wa = *_wa;
@@ -1577,8 +1577,8 @@ static int wpa_scan_result_compar(const 
 
 	if ((wa->flags & wb->flags & WPA_SCAN_LEVEL_DBM) &&
 	    !((wa->flags | wb->flags) & WPA_SCAN_NOISE_INVALID)) {
-		snr_a = MIN(wa->level - wa->noise, GREAT_SNR);
-		snr_b = MIN(wb->level - wb->noise, GREAT_SNR);
+		snr_a = MINAB(wa->level - wa->noise, GREAT_SNR);
+		snr_b = MINAB(wb->level - wb->noise, GREAT_SNR);
 	} else {
 		/* Not suitable information to calculate SNR, so use level */
 		snr_a = wa->level;
@@ -1604,7 +1604,7 @@ static int wpa_scan_result_compar(const 
 	if (snr_b == snr_a)
 		return wb->qual - wa->qual;
 	return snr_b - snr_a;
-#undef MIN
+#undef MINAB
 #undef IS_5GHZ
 }
 
