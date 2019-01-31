--- src/kex.c.orig	2016-10-17 14:28:29 UTC
+++ src/kex.c
@@ -68,34 +68,47 @@
                 libssh2_sha1_final(hash, (value) + len);                \
                 len += SHA_DIGEST_LENGTH;                               \
             }                                                           \
-    }
+    }                                                                   \
 
 
-/* Helper macro called from kex_method_diffie_hellman_group1_sha256_key_exchange */
-#define LIBSSH2_KEX_METHOD_DIFFIE_HELLMAN_SHA256_HASH(value, reqlen, version) \
-    {                                                                      \
-        libssh2_sha256_ctx hash;                                           \
-        unsigned long len = 0;                                             \
-        if (!(value)) {                                                    \
-            value = LIBSSH2_ALLOC(session, reqlen + SHA256_DIGEST_LENGTH); \
-        }                                                                  \
-        if (value)                                                         \
-            while (len < (unsigned long)reqlen) {                          \
-                libssh2_sha256_init(&hash);                                \
-                libssh2_sha256_update(hash, exchange_state->k_value,       \
-                                      exchange_state->k_value_len);        \
-                libssh2_sha256_update(hash, exchange_state->h_sig_comp,    \
-                                      SHA256_DIGEST_LENGTH);               \
-                if (len > 0) {                                             \
-                    libssh2_sha256_update(hash, value, len);               \
-                } else {                                                   \
-                    libssh2_sha256_update(hash, (version), 1);             \
-                    libssh2_sha256_update(hash, session->session_id,       \
-                                          session->session_id_len);        \
-                }                                                          \
-                libssh2_sha256_final(hash, (value) + len);                 \
-                len += SHA256_DIGEST_LENGTH;                               \
-            }                                                              \
+#define LIBSSH2_KEX_METHOD_EC_SHA_VALUE_HASH(value, reqlen, version)                \
+    {                                                                               \
+        if (type == LIBSSH2_EC_CURVE_NISTP256) {                                    \
+            LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(256, value, reqlen, version);         \
+        }                                                                           \
+        else if (type == LIBSSH2_EC_CURVE_NISTP384 ) {                              \
+            LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(384, value, reqlen, version);         \
+        }                                                                           \
+        else if (type == LIBSSH2_EC_CURVE_NISTP521 ) {                              \
+            LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(512, value, reqlen, version);         \
+        }                                                                           \
+}                                                                                   \
+
+
+#define LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(digest_type, value, reqlen, version)          \
+    {                                                                                   \
+        libssh2_sha##digest_type##_ctx hash;                                            \
+        unsigned long len = 0;                                                          \
+        if (!(value)) {                                                                 \
+            value = LIBSSH2_ALLOC(session, reqlen + SHA##digest_type##_DIGEST_LENGTH);  \
+        }                                                                               \
+        if (value)                                                                      \
+            while (len < (unsigned long)reqlen) {                                       \
+                libssh2_sha##digest_type##_init(&hash);                                 \
+                libssh2_sha##digest_type##_update(hash, exchange_state->k_value,        \
+                                    exchange_state->k_value_len);                       \
+                libssh2_sha##digest_type##_update(hash, exchange_state->h_sig_comp,     \
+                                    SHA##digest_type##_DIGEST_LENGTH);                  \
+                if (len > 0) {                                                          \
+                    libssh2_sha##digest_type##_update(hash, value, len);                \
+                }    else {                                                             \
+                    libssh2_sha##digest_type##_update(hash, (version), 1);              \
+                    libssh2_sha##digest_type##_update(hash, session->session_id,        \
+                                        session->session_id_len);                       \
+                }                                                                       \
+                libssh2_sha##digest_type##_final(hash, (value) + len);                  \
+                len += SHA##digest_type##_DIGEST_LENGTH;                                \
+            }                                                                           \
     }
 
 
@@ -304,6 +317,62 @@ static int diffie_hellman_sha1(LIBSSH2_S
                            "Server's SHA1 Fingerprint: %s", fingerprint);
         }
 #endif /* LIBSSH2DEBUG */
+        
+        {
+            libssh2_sha256_ctx fingerprint_ctx;
+            
+            if (libssh2_sha256_init(&fingerprint_ctx)) {
+                libssh2_sha256_update(fingerprint_ctx, session->server_hostkey,
+                                    session->server_hostkey_len);
+                libssh2_sha256_final(fingerprint_ctx,
+                                   session->server_hostkey_sha256);
+                session->server_hostkey_sha256_valid = TRUE;
+            }
+            else {
+                session->server_hostkey_sha256_valid = FALSE;
+            }
+        }
+#ifdef LIBSSH2DEBUG
+        {
+            char *base64Fingerprint = NULL;
+            _libssh2_base64_encode(session, (const char*)session->server_hostkey_sha256,
+                                   SHA256_DIGEST_LENGTH, &base64Fingerprint);
+            if (base64Fingerprint != NULL) {
+                _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                               "Server's SHA256 Fingerprint: %s", base64Fingerprint);
+                LIBSSH2_FREE(session, base64Fingerprint);
+            }
+        }
+#endif /* LIBSSH2DEBUG */
+
+
+        {
+            libssh2_sha256_ctx fingerprint_ctx;
+
+            if (libssh2_sha256_init(&fingerprint_ctx)) {
+                libssh2_sha256_update(fingerprint_ctx, session->server_hostkey,
+                                    session->server_hostkey_len);
+                libssh2_sha256_final(fingerprint_ctx,
+                                   session->server_hostkey_sha256);
+                session->server_hostkey_sha256_valid = TRUE;
+            }
+            else {
+                session->server_hostkey_sha256_valid = FALSE;
+            }
+        }
+#ifdef LIBSSH2DEBUG
+        {
+            char *base64Fingerprint = NULL;
+            _libssh2_base64_encode(session, (const char*)session->server_hostkey_sha256,
+                                   SHA256_DIGEST_LENGTH, &base64Fingerprint);
+            if (base64Fingerprint != NULL) {
+                _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                               "Server's SHA256 Fingerprint: %s", base64Fingerprint);
+                LIBSSH2_FREE(session, base64Fingerprint);
+            }
+        }
+#endif /* LIBSSH2DEBUG */
+
 
         if (session->hostkey->init(session, session->server_hostkey,
                                    session->server_hostkey_len,
@@ -924,6 +993,60 @@ static int diffie_hellman_sha256(LIBSSH2
                            "Server's SHA1 Fingerprint: %s", fingerprint);
         }
 #endif /* LIBSSH2DEBUG */
+        
+        {
+            libssh2_sha256_ctx fingerprint_ctx;
+            
+            if (libssh2_sha256_init(&fingerprint_ctx)) {
+                libssh2_sha256_update(fingerprint_ctx, session->server_hostkey,
+                                      session->server_hostkey_len);
+                libssh2_sha256_final(fingerprint_ctx,
+                                     session->server_hostkey_sha256);
+                session->server_hostkey_sha256_valid = TRUE;
+            }
+            else {
+                session->server_hostkey_sha256_valid = FALSE;
+            }
+        }
+#ifdef LIBSSH2DEBUG
+        {
+            char *base64Fingerprint = NULL;
+            _libssh2_base64_encode(session, (const char*)session->server_hostkey_sha256,
+                                   SHA256_DIGEST_LENGTH, &base64Fingerprint);
+            if (base64Fingerprint != NULL) {
+                _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                               "Server's SHA256 Fingerprint: %s", base64Fingerprint);
+                LIBSSH2_FREE(session, base64Fingerprint);
+            }
+        }
+#endif /* LIBSSH2DEBUG */
+
+        {
+            libssh2_sha256_ctx fingerprint_ctx;
+
+            if (libssh2_sha256_init(&fingerprint_ctx)) {
+                libssh2_sha256_update(fingerprint_ctx, session->server_hostkey,
+                                      session->server_hostkey_len);
+                libssh2_sha256_final(fingerprint_ctx,
+                                     session->server_hostkey_sha256);
+                session->server_hostkey_sha256_valid = TRUE;
+            }
+            else {
+                session->server_hostkey_sha256_valid = FALSE;
+            }
+        }
+#ifdef LIBSSH2DEBUG
+        {
+            char *base64Fingerprint = NULL;
+            _libssh2_base64_encode(session, (const char*)session->server_hostkey_sha256,
+                                   SHA256_DIGEST_LENGTH, &base64Fingerprint);
+            if (base64Fingerprint != NULL) {
+                _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                               "Server's SHA256 Fingerprint: %s", base64Fingerprint);
+                LIBSSH2_FREE(session, base64Fingerprint);
+            }
+        }
+#endif /* LIBSSH2DEBUG */
 
         if (session->hostkey->init(session, session->server_hostkey,
                                    session->server_hostkey_len,
@@ -1137,16 +1260,18 @@ static int diffie_hellman_sha256(LIBSSH2
             unsigned char *iv = NULL, *secret = NULL;
             int free_iv = 0, free_secret = 0;
 
-            LIBSSH2_KEX_METHOD_DIFFIE_HELLMAN_SHA256_HASH(iv,
-                                                          session->local.crypt->
-                                                          iv_len, "A");
+            LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(256, iv,
+                                              session->local.crypt->
+                                              iv_len,
+                                              (const unsigned char *)"A");
             if (!iv) {
                 ret = -1;
                 goto clean_exit;
             }
-            LIBSSH2_KEX_METHOD_DIFFIE_HELLMAN_SHA256_HASH(secret,
-                                                          session->local.crypt->
-                                                          secret_len, "C");
+            LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(256, secret,
+                                              session->local.crypt->
+                                              secret_len,
+                                              (const unsigned char *)"C");
             if (!secret) {
                 LIBSSH2_FREE(session, iv);
                 ret = LIBSSH2_ERROR_KEX_FAILURE;
@@ -1184,16 +1309,18 @@ static int diffie_hellman_sha256(LIBSSH2
             unsigned char *iv = NULL, *secret = NULL;
             int free_iv = 0, free_secret = 0;
 
-            LIBSSH2_KEX_METHOD_DIFFIE_HELLMAN_SHA256_HASH(iv,
-                                                          session->remote.crypt->
-                                                          iv_len, "B");
+            LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(256, iv,
+                                              session->remote.crypt->
+                                              iv_len,
+                                              (const unsigned char *)"B");
             if (!iv) {
                 ret = LIBSSH2_ERROR_KEX_FAILURE;
                 goto clean_exit;
             }
-            LIBSSH2_KEX_METHOD_DIFFIE_HELLMAN_SHA256_HASH(secret,
-                                                          session->remote.crypt->
-                                                          secret_len, "D");
+            LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(256, secret,
+                                              session->remote.crypt->
+                                              secret_len,
+                                              (const unsigned char *)"D");
             if (!secret) {
                 LIBSSH2_FREE(session, iv);
                 ret = LIBSSH2_ERROR_KEX_FAILURE;
@@ -1229,9 +1356,10 @@ static int diffie_hellman_sha256(LIBSSH2
             unsigned char *key = NULL;
             int free_key = 0;
 
-            LIBSSH2_KEX_METHOD_DIFFIE_HELLMAN_SHA256_HASH(key,
-                                                          session->local.mac->
-                                                          key_len, "E");
+            LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(256, key,
+                                              session->local.mac->
+                                              key_len,
+                                              (const unsigned char *)"E");
             if (!key) {
                 ret = LIBSSH2_ERROR_KEX_FAILURE;
                 goto clean_exit;
@@ -1255,9 +1383,10 @@ static int diffie_hellman_sha256(LIBSSH2
             unsigned char *key = NULL;
             int free_key = 0;
 
-            LIBSSH2_KEX_METHOD_DIFFIE_HELLMAN_SHA256_HASH(key,
-                                                          session->remote.mac->
-                                                          key_len, "F");
+            LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(256, key,
+                                              session->remote.mac->
+                                              key_len,
+                                              (const unsigned char *)"F");
             if (!key) {
                 ret = LIBSSH2_ERROR_KEX_FAILURE;
                 goto clean_exit;
@@ -1678,6 +1807,725 @@ kex_method_diffie_hellman_group_exchange
 }
 
 
+#if LIBSSH2_ECDSA
+
+/* kex_session_ecdh_curve_type
+ * returns the EC curve type by name used in key exchange
+ */
+
+static int
+kex_session_ecdh_curve_type(const char *name, libssh2_curve_type *out_type)
+{
+    int ret = 0;
+    libssh2_curve_type type;
+
+    if ( name == NULL )
+        return -1;
+
+    if ( strcmp(name, "ecdh-sha2-nistp256") == 0)
+        type = LIBSSH2_EC_CURVE_NISTP256;
+    else if ( strcmp(name, "ecdh-sha2-nistp384") == 0)
+        type = LIBSSH2_EC_CURVE_NISTP384;
+    else if ( strcmp(name, "ecdh-sha2-nistp521") == 0)
+        type = LIBSSH2_EC_CURVE_NISTP521;
+    else {
+        ret = -1;
+    }
+
+    if (ret == 0 && out_type) {
+        *out_type = type;
+    }
+
+    return ret;
+}
+
+
+/* LIBSSH2_KEX_METHOD_EC_SHA_HASH_CREATE_VERIFY
+ *
+ * Macro that create and verifies EC SHA hash with a given digest bytes
+ *
+ * Payload format:
+ *
+ * string   V_C, client's identification string (CR and LF excluded)
+ * string   V_S, server's identification string (CR and LF excluded)
+ * string   I_C, payload of the client's SSH_MSG_KEXINIT
+ * string   I_S, payload of the server's SSH_MSG_KEXINIT
+ * string   K_S, server's public host key
+ * string   Q_C, client's ephemeral public key octet string
+ * string   Q_S, server's ephemeral public key octet string
+ * mpint    K,   shared secret
+ *
+ */
+
+#define LIBSSH2_KEX_METHOD_EC_SHA_HASH_CREATE_VERIFY(digest_type)                   \
+    {                                                                               \
+                                                                                    \
+        libssh2_sha##digest_type##_ctx ctx;                                         \
+        exchange_state->exchange_hash = (void*)&ctx;                                \
+                                                                                    \
+        libssh2_sha##digest_type##_init(&ctx);                                      \
+        if (session->local.banner) {                                                \
+            _libssh2_htonu32(exchange_state->h_sig_comp,                            \
+            strlen((char *) session->local.banner) - 2);                            \
+            libssh2_sha##digest_type##_update(ctx,                                  \
+              exchange_state->h_sig_comp, 4);                                       \
+            libssh2_sha##digest_type##_update(ctx,                                  \
+              (char *) session->local.banner,                                       \
+              strlen((char *) session->local.banner) - 2);                          \
+        } else {                                                                    \
+            _libssh2_htonu32(exchange_state->h_sig_comp,                            \
+             sizeof(LIBSSH2_SSH_DEFAULT_BANNER) - 1);                               \
+            libssh2_sha##digest_type##_update(ctx,                                  \
+              exchange_state->h_sig_comp, 4);                                       \
+            libssh2_sha##digest_type##_update(ctx,                                  \
+              LIBSSH2_SSH_DEFAULT_BANNER,                                           \
+              sizeof(LIBSSH2_SSH_DEFAULT_BANNER) - 1);                              \
+        }                                                                           \
+                                                                                    \
+        _libssh2_htonu32(exchange_state->h_sig_comp,                                \
+         strlen((char *) session->remote.banner));                                  \
+        libssh2_sha##digest_type##_update(ctx,                                      \
+          exchange_state->h_sig_comp, 4);                                           \
+        libssh2_sha##digest_type##_update(ctx,                                      \
+          session->remote.banner,                                                   \
+          strlen((char *) session->remote.banner));                                 \
+                                                                                    \
+        _libssh2_htonu32(exchange_state->h_sig_comp,                                \
+         session->local.kexinit_len);                                               \
+        libssh2_sha##digest_type##_update(ctx,                                      \
+          exchange_state->h_sig_comp, 4);                                           \
+        libssh2_sha##digest_type##_update(ctx,                                      \
+          session->local.kexinit,                                                   \
+          session->local.kexinit_len);                                              \
+                                                                                    \
+        _libssh2_htonu32(exchange_state->h_sig_comp,                                \
+         session->remote.kexinit_len);                                              \
+        libssh2_sha##digest_type##_update(ctx,                                      \
+          exchange_state->h_sig_comp, 4);                                           \
+        libssh2_sha##digest_type##_update(ctx,                                      \
+          session->remote.kexinit,                                                  \
+          session->remote.kexinit_len);                                             \
+                                                                                    \
+        _libssh2_htonu32(exchange_state->h_sig_comp,                                \
+         session->server_hostkey_len);                                              \
+        libssh2_sha##digest_type##_update(ctx,                                      \
+          exchange_state->h_sig_comp, 4);                                           \
+        libssh2_sha##digest_type##_update(ctx,                                      \
+          session->server_hostkey,                                                  \
+          session->server_hostkey_len);                                             \
+                                                                                    \
+        _libssh2_htonu32(exchange_state->h_sig_comp,                                \
+         public_key_len);                                                           \
+        libssh2_sha##digest_type##_update(ctx,                                      \
+          exchange_state->h_sig_comp, 4);                                           \
+        libssh2_sha##digest_type##_update(ctx,                                      \
+          public_key,                                                               \
+          public_key_len);                                                          \
+                                                                                    \
+        _libssh2_htonu32(exchange_state->h_sig_comp,                                \
+         server_public_key_len);                                                    \
+        libssh2_sha##digest_type##_update(ctx,                                      \
+          exchange_state->h_sig_comp, 4);                                           \
+        libssh2_sha##digest_type##_update(ctx,                                      \
+          server_public_key,                                                        \
+          server_public_key_len);                                                   \
+                                                                                    \
+        libssh2_sha##digest_type##_update(ctx,                                      \
+          exchange_state->k_value,                                                  \
+          exchange_state->k_value_len);                                             \
+                                                                                    \
+        libssh2_sha##digest_type##_final(ctx, exchange_state->h_sig_comp);          \
+                                                                                    \
+        if (session->hostkey->                                                      \
+        sig_verify(session, exchange_state->h_sig,                                  \
+           exchange_state->h_sig_len, exchange_state->h_sig_comp,                   \
+           SHA##digest_type##_DIGEST_LENGTH, &session->server_hostkey_abstract)) {  \
+               rc = -1;                                                             \
+        }                                                                           \
+    }                                                                               \
+
+
+/* ecdh_sha2_nistp
+ * Elliptic Curve Diffie Hellman Key Exchange
+ */
+
+static int ecdh_sha2_nistp(LIBSSH2_SESSION *session, libssh2_curve_type type,
+                           unsigned char *data, size_t data_len, unsigned char *public_key,
+                          size_t public_key_len, _libssh2_ec_key *private_key,
+                          kmdhgGPshakex_state_t *exchange_state)
+{
+    int ret = 0;
+    int rc;
+
+    if (exchange_state->state == libssh2_NB_state_idle) {
+
+        /* Setup initial values */
+        exchange_state->k = _libssh2_bn_init();
+
+        exchange_state->state = libssh2_NB_state_created;
+    }
+
+    if ( exchange_state->state == libssh2_NB_state_created )
+    {
+        /* parse INIT reply data */
+
+        /* host key K_S */
+        unsigned char *s = data + 1; /* Advance past packet type */
+        unsigned char *server_public_key;
+        size_t server_public_key_len;
+        size_t host_sig_len;
+
+        session->server_hostkey_len = _libssh2_ntohu32((const unsigned char*)s);
+        s += 4;
+
+        session->server_hostkey = LIBSSH2_ALLOC(session, session->server_hostkey_len);
+        if (!session->server_hostkey) {
+            ret = _libssh2_error(session, LIBSSH2_ERROR_ALLOC,
+                                 "Unable to allocate memory for a copy "
+                                 "of the host key");
+            goto clean_exit;
+        }
+
+        memcpy(session->server_hostkey, s, session->server_hostkey_len);
+        s += session->server_hostkey_len;
+
+#if LIBSSH2_MD5
+        {
+            libssh2_md5_ctx fingerprint_ctx;
+
+            if (libssh2_md5_init(&fingerprint_ctx)) {
+                libssh2_md5_update(fingerprint_ctx, session->server_hostkey,
+                                   session->server_hostkey_len);
+                libssh2_md5_final(fingerprint_ctx, session->server_hostkey_md5);
+                session->server_hostkey_md5_valid = TRUE;
+            }
+            else {
+                session->server_hostkey_md5_valid = FALSE;
+            }
+        }
+#ifdef LIBSSH2DEBUG
+        {
+            char fingerprint[50], *fprint = fingerprint;
+            int i;
+            for(i = 0; i < 16; i++, fprint += 3) {
+                snprintf(fprint, 4, "%02x:", session->server_hostkey_md5[i]);
+            }
+            *(--fprint) = '\0';
+            _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                           "Server's MD5 Fingerprint: %s", fingerprint);
+        }
+#endif /* LIBSSH2DEBUG */
+#endif /* ! LIBSSH2_MD5 */
+
+        {
+            libssh2_sha1_ctx fingerprint_ctx;
+
+            if (libssh2_sha1_init(&fingerprint_ctx)) {
+                libssh2_sha1_update(fingerprint_ctx, session->server_hostkey,
+                                    session->server_hostkey_len);
+                libssh2_sha1_final(fingerprint_ctx, session->server_hostkey_sha1);
+                session->server_hostkey_sha1_valid = TRUE;
+            }
+            else {
+                session->server_hostkey_sha1_valid = FALSE;
+            }
+        }
+#ifdef LIBSSH2DEBUG
+        {
+            char fingerprint[64], *fprint = fingerprint;
+            int i;
+
+            for(i = 0; i < 20; i++, fprint += 3) {
+                snprintf(fprint, 4, "%02x:", session->server_hostkey_sha1[i]);
+            }
+            *(--fprint) = '\0';
+            _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                           "Server's SHA1 Fingerprint: %s", fingerprint);
+        }
+#endif /* LIBSSH2DEBUG */
+
+        /* SHA256 */
+        {
+            libssh2_sha256_ctx fingerprint_ctx;
+
+            if (libssh2_sha256_init(&fingerprint_ctx)) {
+                libssh2_sha256_update(fingerprint_ctx, session->server_hostkey,
+                                      session->server_hostkey_len);
+                libssh2_sha256_final(fingerprint_ctx, session->server_hostkey_sha256);
+                session->server_hostkey_sha256_valid = TRUE;
+            }
+            else {
+                session->server_hostkey_sha256_valid = FALSE;
+            }
+        }
+#ifdef LIBSSH2DEBUG
+        {
+            char *base64Fingerprint = NULL;
+            _libssh2_base64_encode(session, (const char*)session->server_hostkey_sha256, SHA256_DIGEST_LENGTH, &base64Fingerprint);
+            if ( base64Fingerprint != NULL ) {
+                _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                               "Server's SHA256 Fingerprint: %s", base64Fingerprint);
+                LIBSSH2_FREE(session, base64Fingerprint);
+            }
+        }
+#endif /* LIBSSH2DEBUG */
+
+        if (session->hostkey->init(session, session->server_hostkey,
+                                   session->server_hostkey_len,
+                                   &session->server_hostkey_abstract)) {
+            ret = _libssh2_error(session, LIBSSH2_ERROR_HOSTKEY_INIT,
+                                 "Unable to initialize hostkey importer");
+            goto clean_exit;
+        }
+
+        /* server public key Q_S */
+        server_public_key_len = _libssh2_ntohu32((const unsigned char*)s);
+        s += 4;
+
+        server_public_key = s;
+        s += server_public_key_len;
+
+        /* server signature */
+        host_sig_len = _libssh2_ntohu32((const unsigned char*)s);
+        s += 4;
+
+        exchange_state->h_sig = s;
+        exchange_state->h_sig_len = host_sig_len;
+        s += host_sig_len;
+
+        /* Compute the shared secret K */
+        rc = _libssh2_ecdh_gen_k(&exchange_state->k, private_key, server_public_key, server_public_key_len);
+        if ( rc != 0 ) {
+            ret = _libssh2_error(session, LIBSSH2_ERROR_KEX_FAILURE,
+                                 "Unable to create ECDH shared secret");
+            goto clean_exit;
+        }
+
+        exchange_state->k_value_len = _libssh2_bn_bytes(exchange_state->k) + 5;
+        if (_libssh2_bn_bits(exchange_state->k) % 8) {
+            /* don't need leading 00 */
+            exchange_state->k_value_len--;
+        }
+        exchange_state->k_value =
+        LIBSSH2_ALLOC(session, exchange_state->k_value_len);
+        if (!exchange_state->k_value) {
+            ret = _libssh2_error(session, LIBSSH2_ERROR_ALLOC,
+                                 "Unable to allocate buffer for K");
+            goto clean_exit;
+        }
+        _libssh2_htonu32(exchange_state->k_value,
+                         exchange_state->k_value_len - 4);
+        if (_libssh2_bn_bits(exchange_state->k) % 8) {
+            _libssh2_bn_to_bin(exchange_state->k, exchange_state->k_value + 4);
+        } else {
+            exchange_state->k_value[4] = 0;
+            _libssh2_bn_to_bin(exchange_state->k, exchange_state->k_value + 5);
+        }
+
+        /* verify hash */
+
+        switch ( type ) {
+            case LIBSSH2_EC_CURVE_NISTP256:
+                LIBSSH2_KEX_METHOD_EC_SHA_HASH_CREATE_VERIFY(256);
+                break;
+
+            case LIBSSH2_EC_CURVE_NISTP384:
+                LIBSSH2_KEX_METHOD_EC_SHA_HASH_CREATE_VERIFY(384);
+                break;
+            case LIBSSH2_EC_CURVE_NISTP521:
+                LIBSSH2_KEX_METHOD_EC_SHA_HASH_CREATE_VERIFY(512);
+                break;
+        }
+
+        if ( rc != 0 ) {
+            ret = _libssh2_error(session, LIBSSH2_ERROR_HOSTKEY_SIGN,
+                                 "Unable to verify hostkey signature");
+            goto clean_exit;
+        }
+
+        exchange_state->c = SSH_MSG_NEWKEYS;
+        exchange_state->state = libssh2_NB_state_sent;
+    }
+
+    if (exchange_state->state == libssh2_NB_state_sent) {
+        rc = _libssh2_transport_send(session, &exchange_state->c, 1, NULL, 0);
+        if (rc == LIBSSH2_ERROR_EAGAIN) {
+            return rc;
+        } else if (rc) {
+            ret = _libssh2_error(session, rc, "Unable to send NEWKEYS message");
+            goto clean_exit;
+        }
+
+        exchange_state->state = libssh2_NB_state_sent2;
+    }
+
+    if (exchange_state->state == libssh2_NB_state_sent2) {
+        rc = _libssh2_packet_require(session, SSH_MSG_NEWKEYS,
+                                     &exchange_state->tmp,
+                                     &exchange_state->tmp_len, 0, NULL, 0,
+                                     &exchange_state->req_state);
+        if (rc == LIBSSH2_ERROR_EAGAIN) {
+            return rc;
+        } else if (rc) {
+            ret = _libssh2_error(session, rc, "Timed out waiting for NEWKEYS");
+            goto clean_exit;
+        }
+
+        /* The first key exchange has been performed,
+         switch to active crypt/comp/mac mode */
+        session->state |= LIBSSH2_STATE_NEWKEYS;
+        _libssh2_debug(session, LIBSSH2_TRACE_KEX, "Received NEWKEYS message");
+
+        /* This will actually end up being just packet_type(1)
+         for this packet type anyway */
+        LIBSSH2_FREE(session, exchange_state->tmp);
+
+        if (!session->session_id) {
+
+            size_t digest_length = 0;
+
+            if ( type == LIBSSH2_EC_CURVE_NISTP256 )
+                digest_length = SHA256_DIGEST_LENGTH;
+            else if ( type == LIBSSH2_EC_CURVE_NISTP384 )
+                digest_length = SHA384_DIGEST_LENGTH;
+            else if ( type == LIBSSH2_EC_CURVE_NISTP521 )
+                digest_length = SHA512_DIGEST_LENGTH;
+            else{
+                ret = _libssh2_error(session, LIBSSH2_ERROR_KEX_FAILURE,
+                                     "Unknown SHA digest for EC curve");
+                goto clean_exit;
+
+            }
+            session->session_id = LIBSSH2_ALLOC(session, digest_length);
+            if (!session->session_id) {
+                ret = _libssh2_error(session, LIBSSH2_ERROR_ALLOC,
+                                     "Unable to allocate buffer for SHA digest");
+                goto clean_exit;
+            }
+            memcpy(session->session_id, exchange_state->h_sig_comp,
+                   digest_length);
+             session->session_id_len = digest_length;
+            _libssh2_debug(session, LIBSSH2_TRACE_KEX, "session_id calculated");
+        }
+
+        /* Cleanup any existing cipher */
+        if (session->local.crypt->dtor) {
+            session->local.crypt->dtor(session,
+                                       &session->local.crypt_abstract);
+        }
+
+        /* Calculate IV/Secret/Key for each direction */
+        if (session->local.crypt->init) {
+            unsigned char *iv = NULL, *secret = NULL;
+            int free_iv = 0, free_secret = 0;
+
+            LIBSSH2_KEX_METHOD_EC_SHA_VALUE_HASH(iv,
+                                                 session->local.crypt->
+                                                 iv_len, "A");
+            if (!iv) {
+                ret = -1;
+                goto clean_exit;
+            }
+
+            LIBSSH2_KEX_METHOD_EC_SHA_VALUE_HASH(secret,
+                                                session->local.crypt->
+                                                secret_len, "C");
+
+            if (!secret) {
+                LIBSSH2_FREE(session, iv);
+                ret = LIBSSH2_ERROR_KEX_FAILURE;
+                goto clean_exit;
+            }
+            if (session->local.crypt->
+                init(session, session->local.crypt, iv, &free_iv, secret,
+                     &free_secret, 1, &session->local.crypt_abstract)) {
+                    LIBSSH2_FREE(session, iv);
+                    LIBSSH2_FREE(session, secret);
+                    ret = LIBSSH2_ERROR_KEX_FAILURE;
+                    goto clean_exit;
+                }
+
+            if (free_iv) {
+                memset(iv, 0, session->local.crypt->iv_len);
+                LIBSSH2_FREE(session, iv);
+            }
+
+            if (free_secret) {
+                memset(secret, 0, session->local.crypt->secret_len);
+                LIBSSH2_FREE(session, secret);
+            }
+        }
+        _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                       "Client to Server IV and Key calculated");
+
+        if (session->remote.crypt->dtor) {
+            /* Cleanup any existing cipher */
+            session->remote.crypt->dtor(session,
+                                        &session->remote.crypt_abstract);
+        }
+
+        if (session->remote.crypt->init) {
+            unsigned char *iv = NULL, *secret = NULL;
+            int free_iv = 0, free_secret = 0;
+
+            LIBSSH2_KEX_METHOD_EC_SHA_VALUE_HASH(iv,
+                                                 session->remote.crypt->
+                                                 iv_len, "B");
+
+            if (!iv) {
+                ret = LIBSSH2_ERROR_KEX_FAILURE;
+                goto clean_exit;
+            }
+            LIBSSH2_KEX_METHOD_EC_SHA_VALUE_HASH(secret,
+                                                 session->remote.crypt->
+                                                 secret_len, "D");
+
+            if (!secret) {
+                LIBSSH2_FREE(session, iv);
+                ret = LIBSSH2_ERROR_KEX_FAILURE;
+                goto clean_exit;
+            }
+            if (session->remote.crypt->
+                init(session, session->remote.crypt, iv, &free_iv, secret,
+                     &free_secret, 0, &session->remote.crypt_abstract)) {
+                    LIBSSH2_FREE(session, iv);
+                    LIBSSH2_FREE(session, secret);
+                    ret = LIBSSH2_ERROR_KEX_FAILURE;
+                    goto clean_exit;
+                }
+
+            if (free_iv) {
+                memset(iv, 0, session->remote.crypt->iv_len);
+                LIBSSH2_FREE(session, iv);
+            }
+
+            if (free_secret) {
+                memset(secret, 0, session->remote.crypt->secret_len);
+                LIBSSH2_FREE(session, secret);
+            }
+        }
+        _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                       "Server to Client IV and Key calculated");
+
+        if (session->local.mac->dtor) {
+            session->local.mac->dtor(session, &session->local.mac_abstract);
+        }
+
+        if (session->local.mac->init) {
+            unsigned char *key = NULL;
+            int free_key = 0;
+
+            LIBSSH2_KEX_METHOD_EC_SHA_VALUE_HASH(key,
+                                                 session->local.mac->
+                                                 key_len, "E");
+
+            if (!key) {
+                ret = LIBSSH2_ERROR_KEX_FAILURE;
+                goto clean_exit;
+            }
+            session->local.mac->init(session, key, &free_key,
+                                     &session->local.mac_abstract);
+
+            if (free_key) {
+                memset(key, 0, session->local.mac->key_len);
+                LIBSSH2_FREE(session, key);
+            }
+        }
+        _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                       "Client to Server HMAC Key calculated");
+
+        if (session->remote.mac->dtor) {
+            session->remote.mac->dtor(session, &session->remote.mac_abstract);
+        }
+
+        if (session->remote.mac->init) {
+            unsigned char *key = NULL;
+            int free_key = 0;
+
+            LIBSSH2_KEX_METHOD_EC_SHA_VALUE_HASH(key,
+                                                 session->remote.mac->
+                                                 key_len, "F");
+
+            if (!key) {
+                ret = LIBSSH2_ERROR_KEX_FAILURE;
+                goto clean_exit;
+            }
+            session->remote.mac->init(session, key, &free_key,
+                                      &session->remote.mac_abstract);
+
+            if (free_key) {
+                memset(key, 0, session->remote.mac->key_len);
+                LIBSSH2_FREE(session, key);
+            }
+        }
+        _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                       "Server to Client HMAC Key calculated");
+
+        /* Initialize compression for each direction */
+
+        /* Cleanup any existing compression */
+        if (session->local.comp && session->local.comp->dtor) {
+            session->local.comp->dtor(session, 1,
+                                      &session->local.comp_abstract);
+        }
+
+        if (session->local.comp && session->local.comp->init) {
+            if (session->local.comp->init(session, 1,
+                                          &session->local.comp_abstract)) {
+                ret = LIBSSH2_ERROR_KEX_FAILURE;
+                goto clean_exit;
+            }
+        }
+        _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                       "Client to Server compression initialized");
+
+        if (session->remote.comp && session->remote.comp->dtor) {
+            session->remote.comp->dtor(session, 0,
+                                       &session->remote.comp_abstract);
+        }
+
+        if (session->remote.comp && session->remote.comp->init) {
+            if (session->remote.comp->init(session, 0,
+                                           &session->remote.comp_abstract)) {
+                ret = LIBSSH2_ERROR_KEX_FAILURE;
+                goto clean_exit;
+            }
+        }
+        _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                       "Server to Client compression initialized");
+
+    }
+
+clean_exit:
+    _libssh2_bn_free(exchange_state->k);
+    exchange_state->k = NULL;
+
+    if (exchange_state->k_value) {
+        LIBSSH2_FREE(session, exchange_state->k_value);
+        exchange_state->k_value = NULL;
+    }
+
+    exchange_state->state = libssh2_NB_state_idle;
+
+    return ret;
+}
+
+/* kex_method_ecdh_key_exchange
+ *
+ * Elliptic Curve Diffie Hellman Key Exchange
+ * supports SHA256/384/512 hashes based on negotated ecdh method
+ *
+ */
+
+static int
+kex_method_ecdh_key_exchange
+(LIBSSH2_SESSION * session, key_exchange_state_low_t * key_state)
+{
+    int ret = 0;
+    int rc = 0;
+    unsigned char *s;
+    libssh2_curve_type type;
+
+    if (key_state->state == libssh2_NB_state_idle) {
+
+        key_state->public_key_oct = NULL;
+        key_state->state = libssh2_NB_state_created;
+    }
+
+    if ( key_state->state == libssh2_NB_state_created )
+    {
+        rc = kex_session_ecdh_curve_type(session->kex->name, &type);
+
+        if ( rc != 0 ) {
+            ret = _libssh2_error(session, -1,
+                                 "Unknown KEX nistp curve type");
+            goto ecdh_clean_exit;
+        }
+
+        rc = _libssh2_ecdsa_create_key(&key_state->private_key, &key_state->public_key_oct,
+                                       &key_state->public_key_oct_len, type);
+
+        if ( rc != 0 )
+        {
+            ret = _libssh2_error(session, rc,
+                                 "Unable to create private key");
+            goto ecdh_clean_exit;
+        }
+
+        key_state->request[0] = SSH2_MSG_KEX_ECDH_INIT;
+        s = key_state->request + 1;
+        _libssh2_store_str(&s, (const char*)key_state->public_key_oct, key_state->public_key_oct_len);
+        key_state->request_len = key_state->public_key_oct_len + 5;
+
+        _libssh2_debug(session, LIBSSH2_TRACE_KEX,
+                       "Initiating ECDH SHA2 NISTP256");
+
+        key_state->state = libssh2_NB_state_sent;
+    }
+
+    if ( key_state->state == libssh2_NB_state_sent ) {
+        rc = _libssh2_transport_send(session, key_state->request,
+                                     key_state->request_len, NULL, 0);
+        if (rc == LIBSSH2_ERROR_EAGAIN) {
+            return rc;
+        } else if (rc) {
+            ret = _libssh2_error(session, rc,
+                                 "Unable to send ECDH_INIT");
+            goto ecdh_clean_exit;
+        }
+
+        key_state->state = libssh2_NB_state_sent1;
+    }
+
+    if ( key_state->state == libssh2_NB_state_sent1 ) {
+        rc = _libssh2_packet_require(session, SSH2_MSG_KEX_ECDH_REPLY,
+                                     &key_state->data, &key_state->data_len,
+                                     0, NULL, 0, &key_state->req_state);
+        if (rc == LIBSSH2_ERROR_EAGAIN) {
+            return rc;
+        } else if (rc) {
+            ret = _libssh2_error(session, rc,
+                                 "Timeout waiting for ECDH_REPLY reply");
+            goto ecdh_clean_exit;
+        }
+
+        key_state->state = libssh2_NB_state_sent2;
+    }
+
+    if ( key_state->state == libssh2_NB_state_sent2 ) {
+
+        (void)kex_session_ecdh_curve_type(session->kex->name, &type);
+
+        ret = ecdh_sha2_nistp(session, type, key_state->data, key_state->data_len, (unsigned char*)key_state->public_key_oct,
+                             key_state->public_key_oct_len, key_state->private_key, &key_state->exchange_state);
+
+        if (ret == LIBSSH2_ERROR_EAGAIN) {
+            return ret;
+        }
+
+        LIBSSH2_FREE(session, key_state->data);
+    }
+
+ecdh_clean_exit:
+
+    if (key_state->public_key_oct) {
+        free(key_state->public_key_oct);
+        key_state->public_key_oct = NULL;
+    }
+
+    if (key_state->private_key) {
+        _libssh2_ecdsa_free(key_state->private_key);
+        key_state->private_key = NULL;
+    }
+
+    key_state->state = libssh2_NB_state_idle;
+
+    return ret;
+}
+
+#endif /*LIBSSH2_ECDSA*/
+
+
 #define LIBSSH2_KEX_METHOD_FLAG_REQ_ENC_HOSTKEY     0x0001
 #define LIBSSH2_KEX_METHOD_FLAG_REQ_SIGN_HOSTKEY    0x0002
 
@@ -1707,7 +2555,35 @@ kex_method_diffie_helman_group_exchange_
     LIBSSH2_KEX_METHOD_FLAG_REQ_SIGN_HOSTKEY,
 };
 
+#if LIBSSH2_ECDSA
+static const LIBSSH2_KEX_METHOD
+kex_method_ecdh_sha2_nistp256 = {
+    "ecdh-sha2-nistp256",
+    kex_method_ecdh_key_exchange,
+    LIBSSH2_KEX_METHOD_FLAG_REQ_SIGN_HOSTKEY,
+};
+
+static const LIBSSH2_KEX_METHOD
+kex_method_ecdh_sha2_nistp384 = {
+    "ecdh-sha2-nistp384",
+    kex_method_ecdh_key_exchange,
+    LIBSSH2_KEX_METHOD_FLAG_REQ_SIGN_HOSTKEY,
+};
+
+static const LIBSSH2_KEX_METHOD
+kex_method_ecdh_sha2_nistp521 = {
+    "ecdh-sha2-nistp521",
+    kex_method_ecdh_key_exchange,
+    LIBSSH2_KEX_METHOD_FLAG_REQ_SIGN_HOSTKEY,
+};
+#endif
+
 static const LIBSSH2_KEX_METHOD *libssh2_kex_methods[] = {
+#if LIBSSH2_ECDSA
+    &kex_method_ecdh_sha2_nistp256,
+    &kex_method_ecdh_sha2_nistp384,
+    &kex_method_ecdh_sha2_nistp521,
+#endif
     &kex_method_diffie_helman_group_exchange_sha256,
     &kex_method_diffie_helman_group_exchange_sha1,
     &kex_method_diffie_helman_group14_sha1,
