--- wpa_supplicant/scan.c.orig	2015-09-27 19:02:05 UTC
+++ wpa_supplicant/scan.c
@@ -1657,7 +1657,7 @@ struct wpabuf * wpa_scan_get_vendor_ie_m
  * better. */
 static int wpa_scan_result_compar(const void *a, const void *b)
 {
-#define MIN(a,b) a < b ? a : b
+#define MINAB(a,b) a < b ? a : b
 	struct wpa_scan_res **_wa = (void *) a;
 	struct wpa_scan_res **_wb = (void *) b;
 	struct wpa_scan_res *wa = *_wa;
@@ -1686,9 +1686,9 @@ static int wpa_scan_result_compar(const 
 
 	if (wa->flags & wb->flags & WPA_SCAN_LEVEL_DBM) {
 		snr_a_full = wa->snr;
-		snr_a = MIN(wa->snr, GREAT_SNR);
+		snr_a = MINAB(wa->snr, GREAT_SNR);
 		snr_b_full = wb->snr;
-		snr_b = MIN(wb->snr, GREAT_SNR);
+		snr_b = MINAB(wb->snr, GREAT_SNR);
 	} else {
 		/* Level is not in dBm, so we can't calculate
 		 * SNR. Just use raw level (units unknown). */
@@ -1711,7 +1711,7 @@ static int wpa_scan_result_compar(const 
 	if (snr_b_full == snr_a_full)
 		return wb->qual - wa->qual;
 	return snr_b_full - snr_a_full;
-#undef MIN
+#undef MINAB
 }
 
 
