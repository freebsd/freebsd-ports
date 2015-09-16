--- src/eap_server/eap_server_pwd.c.orig	2015-03-15 17:30:39 UTC
+++ src/eap_server/eap_server_pwd.c
@@ -634,9 +634,21 @@ eap_pwd_process_commit_resp(struct eap_s
 	BIGNUM *x = NULL, *y = NULL, *cofactor = NULL;
 	EC_POINT *K = NULL, *point = NULL;
 	int res = 0;
+	size_t prime_len, order_len;
 
 	wpa_printf(MSG_DEBUG, "EAP-pwd: Received commit response");
 
+	prime_len = BN_num_bytes(data->grp->prime);
+	order_len = BN_num_bytes(data->grp->order);
+
+	if (payload_len != 2 * prime_len + order_len) {
+		wpa_printf(MSG_INFO,
+			   "EAP-pwd: Unexpected Commit payload length %u (expected %u)",
+			   (unsigned int) payload_len,
+			   (unsigned int) (2 * prime_len + order_len));
+		goto fin;
+	}
+
 	if (((data->peer_scalar = BN_new()) == NULL) ||
 	    ((data->k = BN_new()) == NULL) ||
 	    ((cofactor = BN_new()) == NULL) ||
@@ -752,6 +764,13 @@ eap_pwd_process_confirm_resp(struct eap_
 	u8 conf[SHA256_MAC_LEN], *cruft = NULL, *ptr;
 	int offset;
 
+	if (payload_len != SHA256_MAC_LEN) {
+		wpa_printf(MSG_INFO,
+			   "EAP-pwd: Unexpected Confirm payload length %u (expected %u)",
+			   (unsigned int) payload_len, SHA256_MAC_LEN);
+		goto fin;
+	}
+
 	/* build up the ciphersuite: group | random_function | prf */
 	grp = htons(data->group_num);
 	ptr = (u8 *) &cs;
@@ -901,11 +920,21 @@ static void eap_pwd_process(struct eap_s
 	 * the first fragment has a total length
 	 */
 	if (EAP_PWD_GET_LENGTH_BIT(lm_exch)) {
+		if (len < 2) {
+			wpa_printf(MSG_DEBUG,
+				   "EAP-pwd: Frame too short to contain Total-Length field");
+			return;
+		}
 		tot_len = WPA_GET_BE16(pos);
 		wpa_printf(MSG_DEBUG, "EAP-pwd: Incoming fragments, total "
 			   "length = %d", tot_len);
 		if (tot_len > 15000)
 			return;
+		if (data->inbuf) {
+			wpa_printf(MSG_DEBUG,
+				   "EAP-pwd: Unexpected new fragment start when previous fragment is still in use");
+			return;
+		}
 		data->inbuf = wpabuf_alloc(tot_len);
 		if (data->inbuf == NULL) {
 			wpa_printf(MSG_INFO, "EAP-pwd: Out of memory to "
