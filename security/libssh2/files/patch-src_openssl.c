--- src/openssl.c.orig	2016-10-22 14:16:47 UTC
+++ src/openssl.c
@@ -48,6 +48,24 @@
 #define EVP_MAX_BLOCK_LENGTH 32
 #endif
 
+static unsigned char *
+write_bn(unsigned char *buf, const BIGNUM *bn, int bn_bytes)
+{
+    unsigned char *p = buf;
+
+    /* Left space for bn size which will be written below. */
+    p += 4;
+
+    *p = 0;
+    BN_bn2bin(bn, p + 1);
+    if (!(*(p + 1) & 0x80)) {
+        memmove(p, p + 1, --bn_bytes);
+    }
+    _libssh2_htonu32(p - 4, bn_bytes);  /* Post write bn size. */
+
+    return p + bn_bytes;
+}
+
 int
 _libssh2_rsa_new(libssh2_rsa_ctx ** rsa,
                  const unsigned char *edata,
@@ -230,6 +248,144 @@ _libssh2_dsa_sha1_verify(libssh2_dsa_ctx
 }
 #endif /* LIBSSH_DSA */
 
+#if LIBSSH2_ECDSA
+
+/* _libssh2_ecdsa_key_get_curve_type
+ *
+ * returns key curve type that maps to libssh2_curve_type
+ *
+ */
+
+libssh2_curve_type
+_libssh2_ecdsa_key_get_curve_type(_libssh2_ec_key *key)
+{
+    const EC_GROUP *group = EC_KEY_get0_group(key);
+    return EC_GROUP_get_curve_name(group);
+}
+
+/* _libssh2_ecdsa_curve_type_from_name
+ *
+ * returns 0 for success, key curve type that maps to libssh2_curve_type
+ *
+ */
+
+int
+_libssh2_ecdsa_curve_type_from_name(const char *name, libssh2_curve_type *out_type)
+{
+    int ret = 0;
+    libssh2_curve_type type;
+
+    if ( name == NULL || strlen(name) != 19 )
+        return -1;
+
+    if ( strcmp(name, "ecdsa-sha2-nistp256") == 0)
+        type = LIBSSH2_EC_CURVE_NISTP256;
+    else if ( strcmp(name, "ecdsa-sha2-nistp384") == 0)
+        type = LIBSSH2_EC_CURVE_NISTP384;
+    else if ( strcmp(name, "ecdsa-sha2-nistp521") == 0)
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
+/* _libssh2_ecdsa_curve_name_with_octal_new
+ *
+ * Creates a new public key given an octal string, length and type
+ *
+ */
+
+int
+_libssh2_ecdsa_curve_name_with_octal_new(libssh2_ecdsa_ctx ** ec_ctx,
+     const unsigned char *k,
+     size_t k_len, libssh2_curve_type curve)
+{
+
+    int ret = 0;
+    const EC_GROUP *ec_group = NULL;
+    EC_KEY *ec_key = EC_KEY_new_by_curve_name(curve);
+    EC_POINT *point = NULL;
+
+    if ( ec_key ) {
+        ec_group = EC_KEY_get0_group(ec_key);
+        point = EC_POINT_new(ec_group);
+        ret = EC_POINT_oct2point(ec_group, point, k, k_len, NULL);
+        ret = EC_KEY_set_public_key(ec_key, point);
+
+        if (point != NULL)
+            EC_POINT_free(point);
+
+        if ( ec_ctx != NULL )
+            *ec_ctx = ec_key;
+    }
+
+    return (ret == 1) ? 0 : -1;
+}
+
+#define LIBSSH2_ECDSA_VERIFY(digest_type)                           \
+{                                                                   \
+    unsigned char hash[SHA##digest_type##_DIGEST_LENGTH];           \
+    libssh2_sha##digest_type(m, m_len, hash);                       \
+    ret = ECDSA_do_verify(hash, SHA##digest_type##_DIGEST_LENGTH,   \
+      ecdsa_sig, ec_key);                                           \
+                                                                    \
+}
+
+int
+_libssh2_ecdsa_verify(libssh2_ecdsa_ctx * ctx,
+      const unsigned char *r, size_t r_len,
+      const unsigned char *s, size_t s_len,
+      const unsigned char *m, size_t m_len)
+{
+    int ret = 0;
+    EC_KEY *ec_key = (EC_KEY*)ctx;
+    libssh2_curve_type type = _libssh2_ecdsa_key_get_curve_type(ec_key);
+
+#if HAVE_OPAQUE_STRUCTS
+    ECDSA_SIG *ecdsa_sig = ECDSA_SIG_new();
+    BIGNUM *pr = BN_new();
+    BIGNUM *ps = BN_new();
+
+    BN_bin2bn(r, r_len, pr);
+    BN_bin2bn(s, s_len, ps);
+    ECDSA_SIG_set0(ecdsa_sig, pr, ps);
+
+#else
+    ECDSA_SIG ecdsa_sig_;
+    ECDSA_SIG *ecdsa_sig = &ecdsa_sig_;
+    ecdsa_sig_.r = BN_new();
+    BN_bin2bn(r, r_len, ecdsa_sig_.r);
+    ecdsa_sig_.s = BN_new();
+    BN_bin2bn(s, s_len, ecdsa_sig_.s);
+#endif
+
+    if ( type == LIBSSH2_EC_CURVE_NISTP256 ) {
+        LIBSSH2_ECDSA_VERIFY(256);
+    }else if ( type == LIBSSH2_EC_CURVE_NISTP384 ) {
+        LIBSSH2_ECDSA_VERIFY(384);
+    }else if ( type == LIBSSH2_EC_CURVE_NISTP521 ) {
+        LIBSSH2_ECDSA_VERIFY(512);
+    }
+
+#if HAVE_OPAQUE_STRUCTS
+    if ( ecdsa_sig )
+        ECDSA_SIG_free(ecdsa_sig);
+#else
+    BN_clear_free(ecdsa_sig_.s);
+    BN_clear_free(ecdsa_sig_.r);
+#endif
+
+    return (ret == 1) ? 0 : -1;
+}
+
+#endif /* LIBSSH2_ECDSA */
+
 int
 _libssh2_cipher_init(_libssh2_cipher_ctx * h,
                      _libssh2_cipher_type(algo),
@@ -606,6 +762,41 @@ _libssh2_dsa_new_private(libssh2_dsa_ctx
 }
 #endif /* LIBSSH_DSA */
 
+#if LIBSSH2_ECDSA
+
+int
+_libssh2_ecdsa_new_private_frommemory(libssh2_ecdsa_ctx ** ec_ctx,
+                                    LIBSSH2_SESSION * session,
+                                    const char *filedata, size_t filedata_len,
+                                    unsigned const char *passphrase)
+{
+    pem_read_bio_func read_ec =
+        (pem_read_bio_func) &PEM_read_bio_ECPrivateKey;
+    (void) session;
+
+    _libssh2_init_if_needed();
+
+    return read_private_key_from_memory((void **) ec_ctx, read_ec,
+                                        filedata, filedata_len, passphrase);
+}
+
+int
+_libssh2_ecdsa_new_private(libssh2_ecdsa_ctx ** ec_ctx,
+       LIBSSH2_SESSION * session,
+       const char *filename, unsigned const char *passphrase)
+{
+    pem_read_bio_func read_ec = (pem_read_bio_func) &PEM_read_bio_ECPrivateKey;
+    (void) session;
+
+    _libssh2_init_if_needed ();
+
+    return read_private_key_from_file((void **) ec_ctx, read_ec,
+      filename, passphrase);
+}
+
+#endif /* LIBSSH2_ECDSA */
+
+
 int
 _libssh2_rsa_sha1_sign(LIBSSH2_SESSION * session,
                        libssh2_rsa_ctx * rsactx,
@@ -682,6 +873,69 @@ _libssh2_dsa_sha1_sign(libssh2_dsa_ctx *
 }
 #endif /* LIBSSH_DSA */
 
+#if LIBSSH2_ECDSA
+
+int
+_libssh2_ecdsa_sign(LIBSSH2_SESSION * session, libssh2_ecdsa_ctx * ec_ctx,
+    const unsigned char *hash, unsigned long hash_len,
+    unsigned char **signature, size_t *signature_len)
+{
+    int r_len, s_len;
+    int rc = 0;
+    size_t out_buffer_len = 0;
+    unsigned char *sp;
+    const BIGNUM *pr = NULL, *ps = NULL;
+    unsigned char *temp_buffer = NULL;
+    unsigned char *out_buffer = NULL;
+
+    ECDSA_SIG *sig = ECDSA_do_sign(hash, hash_len, ec_ctx);
+    if ( sig == NULL )
+        return -1;
+#if HAVE_OPAQUE_STRUCTS
+    ECDSA_SIG_get0(sig, &pr, &ps);
+#else
+    pr = sig->r;
+    ps = sig->s;
+#endif
+
+    r_len = BN_num_bytes(pr) + 1;
+    s_len = BN_num_bytes(ps) + 1;
+
+    temp_buffer = malloc(r_len + s_len + 8);
+    if ( temp_buffer == NULL ) {
+        rc = -1;
+        goto clean_exit;
+    }
+
+    sp = temp_buffer;
+    sp = write_bn(sp, pr, r_len);
+    sp = write_bn(sp, ps, s_len);
+
+    out_buffer_len = (size_t)(sp - temp_buffer);
+
+    out_buffer = LIBSSH2_CALLOC(session, out_buffer_len);
+    if ( out_buffer == NULL ) {
+        rc = -1;
+        goto clean_exit;
+    }
+
+    memcpy(out_buffer, temp_buffer, out_buffer_len);
+
+    *signature = out_buffer;
+    *signature_len = out_buffer_len;
+
+clean_exit:
+
+    if ( temp_buffer != NULL )
+        free(temp_buffer);
+
+    if ( sig )
+        ECDSA_SIG_free(sig);
+
+    return rc;
+}
+#endif /* LIBSSH2_ECDSA */
+
 int
 _libssh2_sha1_init(libssh2_sha1_ctx *ctx)
 {
@@ -787,7 +1041,7 @@ _libssh2_sha256(const unsigned char *mes
 }
 
 int
-_libssh2_md5_init(libssh2_md5_ctx *ctx)
+_libssh2_sha384_init(libssh2_sha384_ctx *ctx)
 {
 #ifdef HAVE_OPAQUE_STRUCTS
     *ctx = EVP_MD_CTX_new();
@@ -795,7 +1049,7 @@ _libssh2_md5_init(libssh2_md5_ctx *ctx)
     if (*ctx == NULL)
         return 0;
 
-    if (EVP_DigestInit(*ctx, EVP_get_digestbyname("md5")))
+    if (EVP_DigestInit(*ctx, EVP_get_digestbyname("sha384")))
         return 1;
 
     EVP_MD_CTX_free(*ctx);
@@ -804,26 +1058,112 @@ _libssh2_md5_init(libssh2_md5_ctx *ctx)
     return 0;
 #else
     EVP_MD_CTX_init(ctx);
-    return EVP_DigestInit(ctx, EVP_get_digestbyname("md5"));
+    return EVP_DigestInit(ctx, EVP_get_digestbyname("sha384"));
 #endif
 }
 
-static unsigned char *
-write_bn(unsigned char *buf, const BIGNUM *bn, int bn_bytes)
+int
+_libssh2_sha384(const unsigned char *message, unsigned long len,
+    unsigned char *out)
 {
-    unsigned char *p = buf;
+#ifdef HAVE_OPAQUE_STRUCTS
+    EVP_MD_CTX * ctx = EVP_MD_CTX_new();
 
-    /* Left space for bn size which will be written below. */
-    p += 4;
+    if (ctx == NULL)
+        return 1; /* error */
 
-    *p = 0;
-    BN_bn2bin(bn, p + 1);
-    if (!(*(p + 1) & 0x80)) {
-        memmove(p, p + 1, --bn_bytes);
+    if(EVP_DigestInit(ctx, EVP_get_digestbyname("sha384"))) {
+        EVP_DigestUpdate(ctx, message, len);
+        EVP_DigestFinal(ctx, out, NULL);
+        EVP_MD_CTX_free(ctx);
+        return 0; /* success */
     }
-    _libssh2_htonu32(p - 4, bn_bytes);  /* Post write bn size. */
+    EVP_MD_CTX_free(ctx);
+#else
+    EVP_MD_CTX ctx;
 
-    return p + bn_bytes;
+    EVP_MD_CTX_init(&ctx);
+    if(EVP_DigestInit(&ctx, EVP_get_digestbyname("sha384"))) {
+        EVP_DigestUpdate(&ctx, message, len);
+        EVP_DigestFinal(&ctx, out, NULL);
+        return 0; /* success */
+    }
+#endif
+    return 1; /* error */
+}
+
+int
+_libssh2_sha512_init(libssh2_sha512_ctx *ctx)
+{
+#ifdef HAVE_OPAQUE_STRUCTS
+    *ctx = EVP_MD_CTX_new();
+
+    if (*ctx == NULL)
+        return 0;
+
+    if (EVP_DigestInit(*ctx, EVP_get_digestbyname("sha512")))
+        return 1;
+
+    EVP_MD_CTX_free(*ctx);
+    *ctx = NULL;
+
+    return 0;
+#else
+    EVP_MD_CTX_init(ctx);
+    return EVP_DigestInit(ctx, EVP_get_digestbyname("sha512"));
+#endif
+}
+
+int
+_libssh2_sha512(const unsigned char *message, unsigned long len,
+    unsigned char *out)
+{
+#ifdef HAVE_OPAQUE_STRUCTS
+    EVP_MD_CTX * ctx = EVP_MD_CTX_new();
+
+    if (ctx == NULL)
+        return 1; /* error */
+
+    if(EVP_DigestInit(ctx, EVP_get_digestbyname("sha512"))) {
+        EVP_DigestUpdate(ctx, message, len);
+        EVP_DigestFinal(ctx, out, NULL);
+        EVP_MD_CTX_free(ctx);
+        return 0; /* success */
+    }
+    EVP_MD_CTX_free(ctx);
+#else
+    EVP_MD_CTX ctx;
+
+    EVP_MD_CTX_init(&ctx);
+    if(EVP_DigestInit(&ctx, EVP_get_digestbyname("sha512"))) {
+        EVP_DigestUpdate(&ctx, message, len);
+        EVP_DigestFinal(&ctx, out, NULL);
+        return 0; /* success */
+    }
+#endif
+    return 1; /* error */
+}
+
+int
+_libssh2_md5_init(libssh2_md5_ctx *ctx)
+{
+#ifdef HAVE_OPAQUE_STRUCTS
+    *ctx = EVP_MD_CTX_new();
+
+    if (*ctx == NULL)
+        return 0;
+
+    if (EVP_DigestInit(*ctx, EVP_get_digestbyname("md5")))
+        return 1;
+
+    EVP_MD_CTX_free(*ctx);
+    *ctx = NULL;
+
+    return 0;
+#else
+    EVP_MD_CTX_init(ctx);
+    return EVP_DigestInit(ctx, EVP_get_digestbyname("md5"));
+#endif
 }
 
 static unsigned char *
@@ -1036,6 +1376,272 @@ gen_publickey_from_dsa_evp(LIBSSH2_SESSI
 }
 #endif /* LIBSSH_DSA */
 
+#if LIBSSH2_ECDSA
+
+static int
+gen_publickey_from_ec_evp(LIBSSH2_SESSION *session,
+                          unsigned char **method,
+                          size_t *method_len,
+                          unsigned char **pubkeydata,
+                          size_t *pubkeydata_len,
+                          EVP_PKEY *pk)
+{
+    int rc = 0;
+    EC_KEY *ec = NULL;
+    unsigned char *p;
+    unsigned char* method_buf = NULL;
+    unsigned char *key;
+    size_t  key_len = 0;
+    unsigned char *octal_value = NULL;
+    size_t octal_len;
+    const EC_POINT *public_key;
+    const EC_GROUP *group;
+    BN_CTX *bn_ctx;
+    libssh2_curve_type type;
+
+    _libssh2_debug(session,
+       LIBSSH2_TRACE_AUTH,
+       "Computing public key from EC private key envelop");
+
+    bn_ctx = BN_CTX_new();
+    if ( bn_ctx == NULL )
+        return -1;
+
+    ec = EVP_PKEY_get1_EC_KEY(pk);
+    if ( ec == NULL ) {
+        rc = -1;
+        goto clean_exit;
+    }
+
+    public_key = EC_KEY_get0_public_key(ec);
+    group = EC_KEY_get0_group(ec);
+    type = _libssh2_ecdsa_key_get_curve_type(ec);
+
+    method_buf = LIBSSH2_ALLOC(session, 19);
+    if (method_buf == NULL) {
+        return _libssh2_error(session, LIBSSH2_ERROR_ALLOC,
+            "out of memory");
+    }
+
+    if ( type == LIBSSH2_EC_CURVE_NISTP256 )
+        memcpy(method_buf, "ecdsa-sha2-nistp256", 19);
+    else if ( type == LIBSSH2_EC_CURVE_NISTP384 )
+        memcpy(method_buf, "ecdsa-sha2-nistp384", 19);
+    else if ( type == LIBSSH2_EC_CURVE_NISTP521 )
+        memcpy(method_buf, "ecdsa-sha2-nistp521", 19);
+    else {
+        _libssh2_debug(session,
+            LIBSSH2_TRACE_ERROR,
+            "Unsupported EC private key type");
+        rc = -1;
+        goto clean_exit;
+    }
+
+    /* get length */
+    octal_len = EC_POINT_point2oct(group, public_key, POINT_CONVERSION_UNCOMPRESSED, NULL, 0, bn_ctx);
+    if (octal_len > EC_MAX_POINT_LEN) {
+        rc = -1;
+        goto clean_exit;
+    }
+
+    octal_value = malloc(octal_len);
+    if ( octal_value == NULL ) {
+        rc = -1;
+        goto clean_exit;
+    }
+
+    /* convert to octal */
+    if (EC_POINT_point2oct(group, public_key, POINT_CONVERSION_UNCOMPRESSED,
+       octal_value, octal_len, bn_ctx) != octal_len) {
+           rc = -1;
+           goto clean_exit;
+    }
+
+    /* Key form is: type_len(4) + type(19) + domain_len(4) + domain(8) + pub_key_len(4) + pub_key(~65). */
+    key_len = 4 + 19 + 4 + 8 + 4 + octal_len;
+    key = LIBSSH2_ALLOC(session, key_len);
+    if (key == NULL) {
+        rc = -1;
+        goto  clean_exit;
+    }
+
+    /* Process key encoding. */
+    p = key;
+
+    /* Key type */
+    _libssh2_store_str(&p, (const char*)method_buf, 19);
+
+    /* Name domain */
+    _libssh2_store_str(&p, (const char*)method_buf + 11, 8);
+
+    /* Public key */
+    _libssh2_store_str(&p, (const char*)octal_value, octal_len);
+
+    *method         = method_buf;
+    *method_len     = 19;
+    *pubkeydata     = key;
+    *pubkeydata_len = key_len;
+
+clean_exit:
+
+    if ( ec != NULL)
+        EC_KEY_free(ec);
+
+    if (bn_ctx != NULL) {
+        BN_CTX_free(bn_ctx);
+    }
+
+    if ( octal_value != NULL )
+        free(octal_value);
+
+    if ( rc == 0 )
+        return 0;
+
+    if (method_buf != NULL )
+        LIBSSH2_FREE(session, method_buf);
+
+    return -1;
+}
+
+/*
+ * _libssh2_ecdsa_create_key
+ *
+ * Creates a local private key based on input curve
+ * and returns octal value and octal length
+ *
+ */
+
+int
+_libssh2_ecdsa_create_key(_libssh2_ec_key **out_private_key,
+                          unsigned char **out_public_key_octal,
+                          size_t *out_public_key_octal_len, libssh2_curve_type curve_type)
+{
+    int ret = 1;
+    size_t octal_len = 0;
+    unsigned char octal_value[EC_MAX_POINT_LEN];
+    const EC_POINT *public_key = NULL;
+    EC_KEY *private_key = NULL;
+    const EC_GROUP *group = NULL;
+
+    /* create key */
+    BN_CTX *bn_ctx = BN_CTX_new();
+    if (!bn_ctx)
+        return -1;
+
+    private_key = EC_KEY_new_by_curve_name(curve_type);
+    group = EC_KEY_get0_group(private_key);
+
+    EC_KEY_generate_key(private_key);
+    public_key = EC_KEY_get0_public_key(private_key);
+
+    /* get length */
+    octal_len = EC_POINT_point2oct(group, public_key, POINT_CONVERSION_UNCOMPRESSED, NULL, 0, bn_ctx);
+    if (octal_len > EC_MAX_POINT_LEN) {
+        ret = -1;
+        goto clean_exit;
+    }
+
+    /* convert to octal */
+    if (EC_POINT_point2oct(group, public_key, POINT_CONVERSION_UNCOMPRESSED,
+       octal_value, octal_len, bn_ctx) != octal_len){
+           ret = -1;
+           goto clean_exit;
+    }
+
+    if (out_private_key != NULL)
+        *out_private_key = private_key;
+
+    if (out_public_key_octal) {
+        *out_public_key_octal = malloc(octal_len);
+        if (out_public_key_octal == NULL) {
+            ret = -1;
+            goto clean_exit;
+        }
+
+        memcpy(*out_public_key_octal, octal_value, octal_len);
+    }
+
+    if (out_public_key_octal_len != NULL)
+        *out_public_key_octal_len = octal_len;
+
+clean_exit:
+
+    if (bn_ctx)
+        BN_CTX_free(bn_ctx);
+
+    return (ret == 1) ? 0 : -1;
+}
+
+/* _libssh2_ecdh_gen_k
+ *
+ * Computes the shared secret K given a local private key,
+ * remote public key and length
+ */
+
+int
+_libssh2_ecdh_gen_k(_libssh2_bn **k, _libssh2_ec_key *private_key,
+    const unsigned char *server_public_key, size_t server_public_key_len)
+{
+    int ret = 0;
+    int rc;
+    size_t secret_len;
+    unsigned char *secret;
+    const EC_GROUP *private_key_group;
+    EC_POINT *server_public_key_point;
+
+    BN_CTX *bn_ctx = BN_CTX_new();
+
+    if ( !bn_ctx )
+        return -1;
+
+    if ( k == NULL )
+        return -1;
+
+    private_key_group = EC_KEY_get0_group(private_key);
+
+    server_public_key_point = EC_POINT_new(private_key_group);
+    if ( server_public_key_point == NULL )
+        return -1;
+
+    rc = EC_POINT_oct2point(private_key_group, server_public_key_point, server_public_key, server_public_key_len, bn_ctx);
+    if ( rc != 1 ) {
+        ret = -1;
+        goto clean_exit;
+    }
+
+    secret_len = (EC_GROUP_get_degree(private_key_group) + 7) / 8;
+    secret = malloc(secret_len);
+    if (!secret) {
+        ret = -1;
+        goto clean_exit;
+    }
+
+    secret_len = ECDH_compute_key(secret, secret_len, server_public_key_point, private_key, NULL);
+
+    if( secret_len <= 0 || secret_len > EC_MAX_POINT_LEN ) {
+        ret = -1;
+        goto clean_exit;
+    }
+
+    BN_bin2bn(secret, secret_len, *k);
+
+clean_exit:
+
+    if ( server_public_key_point != NULL )
+        EC_POINT_free(server_public_key_point);
+
+    if ( bn_ctx != NULL )
+        BN_CTX_free(bn_ctx);
+
+    if ( secret != NULL )
+        free(secret);
+
+    return ret;
+}
+
+
+#endif /* LIBSSH2_ECDSA */
+
 int
 _libssh2_pub_priv_keyfile(LIBSSH2_SESSION *session,
                           unsigned char **method,
@@ -1102,6 +1708,13 @@ _libssh2_pub_priv_keyfile(LIBSSH2_SESSIO
         break;
 #endif /* LIBSSH_DSA */
 
+#if LIBSSH2_ECDSA
+    case EVP_PKEY_EC :
+        st = gen_publickey_from_ec_evp(
+            session, method, method_len, pubkeydata, pubkeydata_len, pk);
+    break;
+#endif
+
     default :
         st = _libssh2_error(session,
                             LIBSSH2_ERROR_FILE,
@@ -1176,6 +1789,12 @@ _libssh2_pub_priv_keyfilememory(LIBSSH2_
                                         pubkeydata, pubkeydata_len, pk);
         break;
 #endif /* LIBSSH_DSA */
+#if LIBSSH2_ECDSA
+    case EVP_PKEY_EC :
+        st = gen_publickey_from_ec_evp(session, method, method_len,
+                                       pubkeydata, pubkeydata_len, pk);
+    break;
+#endif
     default :
         st = _libssh2_error(session,
                             LIBSSH2_ERROR_FILE,
