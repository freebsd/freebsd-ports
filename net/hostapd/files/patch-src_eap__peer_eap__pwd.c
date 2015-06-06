--- src/eap_peer/eap_pwd.c.orig	2015-03-15 17:30:39 UTC
+++ src/eap_peer/eap_pwd.c
@@ -301,6 +301,23 @@ eap_pwd_perform_commit_exchange(struct e
 	BIGNUM *mask = NULL, *x = NULL, *y = NULL, *cofactor = NULL;
 	u16 offset;
 	u8 *ptr, *scalar = NULL, *element = NULL;
+	size_t prime_len, order_len;
+
+	if (data->state != PWD_Commit_Req) {
+		ret->ignore = TRUE;
+		goto fin;
+	}
+
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
 
 	if (((data->private_value = BN_new()) == NULL) ||
 	    ((data->my_element = EC_POINT_new(data->grp->group)) == NULL) ||
@@ -500,6 +517,18 @@ eap_pwd_perform_confirm_exchange(struct 
 	u8 conf[SHA256_MAC_LEN], *cruft = NULL, *ptr;
 	int offset;
 
+	if (data->state != PWD_Confirm_Req) {
+		ret->ignore = TRUE;
+		goto fin;
+	}
+
+	if (payload_len != SHA256_MAC_LEN) {
+		wpa_printf(MSG_INFO,
+			   "EAP-pwd: Unexpected Confirm payload length %u (expected %u)",
+			   (unsigned int) payload_len, SHA256_MAC_LEN);
+		goto fin;
+	}
+
 	/*
 	 * first build up the ciphersuite which is group | random_function |
 	 *	prf
@@ -783,11 +812,23 @@ eap_pwd_process(struct eap_sm *sm, void 
 	 * if it's the first fragment there'll be a length field
 	 */
 	if (EAP_PWD_GET_LENGTH_BIT(lm_exch)) {
+		if (len < 2) {
+			wpa_printf(MSG_DEBUG,
+				   "EAP-pwd: Frame too short to contain Total-Length field");
+			ret->ignore = TRUE;
+			return NULL;
+		}
 		tot_len = WPA_GET_BE16(pos);
 		wpa_printf(MSG_DEBUG, "EAP-pwd: Incoming fragments whose "
 			   "total length = %d", tot_len);
 		if (tot_len > 15000)
 			return NULL;
+		if (data->inbuf) {
+			wpa_printf(MSG_DEBUG,
+				   "EAP-pwd: Unexpected new fragment start when previous fragment is still in use");
+			ret->ignore = TRUE;
+			return NULL;
+		}
 		data->inbuf = wpabuf_alloc(tot_len);
 		if (data->inbuf == NULL) {
 			wpa_printf(MSG_INFO, "Out of memory to buffer "
@@ -873,6 +914,7 @@ eap_pwd_process(struct eap_sm *sm, void 
 	/*
 	 * we have output! Do we need to fragment it?
 	 */
+	lm_exch = EAP_PWD_GET_EXCHANGE(lm_exch);
 	len = wpabuf_len(data->outbuf);
 	if ((len + EAP_PWD_HDR_SIZE) > data->mtu) {
 		resp = eap_msg_alloc(EAP_VENDOR_IETF, EAP_TYPE_PWD, data->mtu,
