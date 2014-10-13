--- src/drivers/driver_bsd.c.orig	2014-10-09 14:41:31 UTC
+++ src/drivers/driver_bsd.c
@@ -1334,7 +1334,13 @@ wpa_driver_bsd_add_scan_entry(struct wpa
 	*pos++ = 1;
 	*pos++ = sr->isr_erp;
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
+ || defined(__DragonFly__)
+	os_memcpy(pos, (u8 *)(sr + 1) + sr->isr_ssid_len + sr->isr_meshid_len,
+		sr->isr_ie_len);
+#else
 	os_memcpy(pos, (u8 *)(sr + 1) + sr->isr_ssid_len, sr->isr_ie_len);
+#endif
 	pos += sr->isr_ie_len;
 
 	result->ie_len = pos - (u8 *)(result + 1);
