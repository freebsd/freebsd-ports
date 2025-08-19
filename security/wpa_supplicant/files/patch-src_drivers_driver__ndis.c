--- src/drivers/driver_ndis.c.orig	2024-07-20 18:04:37 UTC
+++ src/drivers/driver_ndis.c
@@ -504,13 +504,13 @@ static int ndis_get_oid(struct wpa_driver_ndis_data *d
 	o->Length = len;
 
 	if (!PacketRequest(drv->adapter, FALSE, o)) {
-		wpa_printf(MSG_DEBUG, "%s: oid=0x%x len (%d) failed",
+		wpa_printf(MSG_DEBUG, "%s: oid=0x%x len (%lu) failed",
 			   __func__, oid, len);
 		os_free(buf);
 		return -1;
 	}
 	if (o->Length > len) {
-		wpa_printf(MSG_DEBUG, "%s: oid=0x%x Length (%d) > len (%d)",
+		wpa_printf(MSG_DEBUG, "%s: oid=0x%x Length (%d) > len (%lu)",
 			   __func__, oid, (unsigned int) o->Length, len);
 		os_free(buf);
 		return -1;
@@ -573,7 +573,7 @@ static int ndis_set_oid(struct wpa_driver_ndis_data *d
 		os_memcpy(o->Data, data, len);
 
 	if (!PacketRequest(drv->adapter, TRUE, o)) {
-		wpa_printf(MSG_DEBUG, "%s: oid=0x%x len (%d) failed",
+		wpa_printf(MSG_DEBUG, "%s: oid=0x%x len (%lu) failed",
 			   __func__, oid, len);
 		os_free(buf);
 		return -1;
@@ -1543,7 +1543,7 @@ static void wpa_driver_ndis_event_auth(struct wpa_driv
 
 	if (data_len < sizeof(*req)) {
 		wpa_printf(MSG_DEBUG, "NDIS: Too short Authentication Request "
-			   "Event (len=%d)", data_len);
+			   "Event (len=%lu)", data_len);
 		return;
 	}
 	req = (NDIS_802_11_AUTHENTICATION_REQUEST *) data;
@@ -1577,7 +1577,7 @@ static void wpa_driver_ndis_event_pmkid(struct wpa_dri
 
 	if (data_len < 8) {
 		wpa_printf(MSG_DEBUG, "NDIS: Too short PMKID Candidate List "
-			   "Event (len=%d)", data_len);
+			   "Event (len=%lu)", data_len);
 		return;
 	}
 	pmkid = (NDIS_802_11_PMKID_CANDIDATE_LIST *) data;
@@ -1599,7 +1599,7 @@ static void wpa_driver_ndis_event_pmkid(struct wpa_dri
 	os_memset(&event, 0, sizeof(event));
 	for (i = 0; i < pmkid->NumCandidates; i++) {
 		PMKID_CANDIDATE *p = &pmkid->CandidateList[i];
-		wpa_printf(MSG_DEBUG, "NDIS: %d: " MACSTR " Flags 0x%x",
+		wpa_printf(MSG_DEBUG, "NDIS: %lu: " MACSTR " Flags 0x%x",
 			   i, MAC2STR(p->BSSID), (int) p->Flags);
 		os_memcpy(event.pmkid_candidate.bssid, p->BSSID, ETH_ALEN);
 		event.pmkid_candidate.index = i;
@@ -1790,7 +1790,7 @@ static void wpa_driver_ndis_get_capability(struct wpa_
 				   "overflow");
 			break;
 		}
-		wpa_printf(MSG_MSGDUMP, "NDIS: %d - auth %d encr %d",
+		wpa_printf(MSG_MSGDUMP, "NDIS: %lu - auth %d encr %d",
 			   i, (int) ae->AuthModeSupported,
 			   (int) ae->EncryptStatusSupported);
 		switch (ae->AuthModeSupported) {
@@ -2118,7 +2118,11 @@ static int wpa_driver_ndis_get_names(struct wpa_driver
 		dlen = dpos - desc;
 	else
 		dlen = os_strlen(desc);
-	drv->adapter_desc = dup_binstr(desc, dlen);
+	drv->adapter_desc = os_malloc(dlen + 1);
+	if (drv->adapter_desc) {
+		os_memcpy(drv->adapter_desc, desc, dlen);
+		drv->adapter_desc[dlen] = '\0';
+	}
 	os_free(b);
 	if (drv->adapter_desc == NULL)
 		return -1;
@@ -2286,7 +2290,11 @@ static int wpa_driver_ndis_get_names(struct wpa_driver
 	} else {
 		dlen = os_strlen(desc[i]);
 	}
-	drv->adapter_desc = dup_binstr(desc[i], dlen);
+	drv->adapter_desc = os_malloc(dlen + 1);
+	if (drv->adapter_desc) {
+		os_memcpy(drv->adapter_desc, desc[i], dlen);
+		drv->adapter_desc[dlen] = '\0';
+	}
 	os_free(names);
 	if (drv->adapter_desc == NULL)
 		return -1;
