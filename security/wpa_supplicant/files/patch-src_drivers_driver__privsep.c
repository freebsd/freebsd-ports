--- src/drivers/driver_privsep.c.orig	2014-10-09 14:41:31 UTC
+++ src/drivers/driver_privsep.c
@@ -228,7 +228,7 @@ static int wpa_driver_privsep_associate(
 
 	wpa_printf(MSG_DEBUG, "%s: priv=%p freq=%d pairwise_suite=%d "
 		   "group_suite=%d key_mgmt_suite=%d auth_alg=%d mode=%d",
-		   __func__, priv, params->freq, params->pairwise_suite,
+		   __func__, priv, params->freq.freq, params->pairwise_suite,
 		   params->group_suite, params->key_mgmt_suite,
 		   params->auth_alg, params->mode);
 
@@ -241,7 +241,7 @@ static int wpa_driver_privsep_associate(
 		os_memcpy(data->bssid, params->bssid, ETH_ALEN);
 	os_memcpy(data->ssid, params->ssid, params->ssid_len);
 	data->ssid_len = params->ssid_len;
-	data->freq = params->freq;
+	data->freq = params->freq.freq;
 	data->pairwise_suite = params->pairwise_suite;
 	data->group_suite = params->group_suite;
 	data->key_mgmt_suite = params->key_mgmt_suite;
