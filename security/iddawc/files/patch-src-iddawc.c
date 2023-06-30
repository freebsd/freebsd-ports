--- src/iddawc.c.orig	2022-12-17 21:23:54 UTC
+++ src/iddawc.c
@@ -4972,7 +4972,7 @@ int i_verify_id_token(struct _i_session * i_session) {
                 if (alg != GNUTLS_DIG_UNKNOWN) {
                   hash_data.data = (unsigned char*)i_session->access_token;
                   hash_data.size = (unsigned int)o_strlen(i_session->access_token);
-                  if (gnutls_fingerprint(alg, &hash_data, hash, &hash_len) == GNUTLS_E_SUCCESS) {
+                  if (gnutls_fingerprint((gnutls_digest_algorithm_t) alg, &hash_data, hash, &hash_len) == GNUTLS_E_SUCCESS) {
                     if (o_base64url_encode(hash, hash_len/2, hash_encoded, &hash_encoded_len)) {
                       if (o_strncmp((const char *)hash_encoded, json_string_value(json_object_get(i_session->id_token_payload, "at_hash")), hash_encoded_len) != 0) {
                         y_log_message(Y_LOG_LEVEL_DEBUG, "i_verify_id_token at - at_hash invalid");
@@ -5000,7 +5000,7 @@ int i_verify_id_token(struct _i_session * i_session) {
                 if (alg != GNUTLS_DIG_UNKNOWN) {
                   hash_data.data = (unsigned char*)i_session->code;
                   hash_data.size = (unsigned int)o_strlen(i_session->code);
-                  if (gnutls_fingerprint(alg, &hash_data, hash, &hash_len) == GNUTLS_E_SUCCESS) {
+                  if (gnutls_fingerprint((gnutls_digest_algorithm_t) alg, &hash_data, hash, &hash_len) == GNUTLS_E_SUCCESS) {
                     if (o_base64url_encode(hash, hash_len/2, hash_encoded, &hash_encoded_len)) {
                       if (o_strncmp((const char *)hash_encoded, json_string_value(json_object_get(i_session->id_token_payload, "c_hash")), hash_encoded_len) != 0) {
                         y_log_message(Y_LOG_LEVEL_DEBUG, "i_verify_id_token - c_hash invalid");
@@ -5028,7 +5028,7 @@ int i_verify_id_token(struct _i_session * i_session) {
                 if (alg != GNUTLS_DIG_UNKNOWN) {
                   hash_data.data = (unsigned char*)i_session->state;
                   hash_data.size = (unsigned int)o_strlen(i_session->state);
-                  if (gnutls_fingerprint(alg, &hash_data, hash, &hash_len) == GNUTLS_E_SUCCESS) {
+                  if (gnutls_fingerprint((gnutls_digest_algorithm_t) alg, &hash_data, hash, &hash_len) == GNUTLS_E_SUCCESS) {
                     if (o_base64url_encode(hash, hash_len/2, hash_encoded, &hash_encoded_len)) {
                       if (o_strncmp((const char *)hash_encoded, json_string_value(json_object_get(i_session->id_token_payload, "s_hash")), hash_encoded_len) != 0) {
                         y_log_message(Y_LOG_LEVEL_DEBUG, "i_verify_id_token - s_hash invalid");
