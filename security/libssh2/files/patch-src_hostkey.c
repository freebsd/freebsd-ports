--- src/hostkey.c.orig	2016-01-18 12:41:58 UTC
+++ src/hostkey.c
@@ -483,7 +483,296 @@ static const LIBSSH2_HOSTKEY_METHOD host
 };
 #endif /* LIBSSH2_DSA */
 
+#if LIBSSH2_ECDSA
+
+/* ***********
+ * ecdsa-sha2-nistp256/384/521 *
+ *********** */
+
+static int
+hostkey_method_ssh_ecdsa_dtor(LIBSSH2_SESSION * session,
+                              void **abstract);
+
+/*
+ * hostkey_method_ssh_ecdsa_init
+ *
+ * Initialize the server hostkey working area with e/n pair
+ */
+static int
+hostkey_method_ssh_ecdsa_init(LIBSSH2_SESSION * session,
+                          const unsigned char *hostkey_data,
+                          size_t hostkey_data_len,
+                          void **abstract)
+{
+    libssh2_ecdsa_ctx *ecdsactx = NULL;
+    const unsigned char *s, *k;
+    size_t len, key_len, n_len;
+    libssh2_curve_type type;
+
+    if (abstract != NULL && *abstract) {
+        hostkey_method_ssh_ecdsa_dtor(session, abstract);
+        *abstract = NULL;
+    }
+
+    if ( hostkey_data_len < 23 )
+        return -1;
+
+    s = hostkey_data;
+    len = _libssh2_ntohu32(s);
+    s += 4;
+
+    if (len != 19 )
+        return -1;
+
+    if (strncmp((char*) s, "ecdsa-sha2-nistp256", 19) == 0 ) {
+        type = LIBSSH2_EC_CURVE_NISTP256;
+    } else if(strncmp((char*) s, "ecdsa-sha2-nistp384", 19) == 0 ) {
+        type = LIBSSH2_EC_CURVE_NISTP384;
+    } else if(strncmp((char*) s, "ecdsa-sha2-nistp521", 19) == 0 ) {
+        type = LIBSSH2_EC_CURVE_NISTP521;
+    } else {
+        return -1;
+    }
+    s += 19;
+
+    /* Domain length */
+    n_len = _libssh2_ntohu32(s);
+    s += 4;
+
+    if (n_len != 8)
+        return -1;
+
+    if ( type == LIBSSH2_EC_CURVE_NISTP256 && strncmp((char*)s, "nistp256", 8) != 0) {
+        return -1;
+    } else if ( type == LIBSSH2_EC_CURVE_NISTP384 && strncmp((char*)s, "nistp384", 8) != 0) {
+        return -1;
+    } else if ( type == LIBSSH2_EC_CURVE_NISTP521 && strncmp((char*)s, "nistp521", 8) != 0) {
+        return -1;
+    }
+
+    s += 8;
+
+    /* public key */
+    key_len = _libssh2_ntohu32(s);
+    s += 4;
+
+    k = s;
+
+    if (_libssh2_ecdsa_curve_name_with_octal_new(&ecdsactx, k, key_len, type) )
+        return -1;
+
+    if ( abstract != NULL )
+        *abstract = ecdsactx;
+
+    return 0;
+}
+
+/*
+ * hostkey_method_ssh_ecdsa_initPEM
+ *
+ * Load a Private Key from a PEM file
+ */
+static int
+hostkey_method_ssh_ecdsa_initPEM(LIBSSH2_SESSION * session,
+                             const char *privkeyfile,
+                             unsigned const char *passphrase,
+                             void **abstract)
+{
+    libssh2_ecdsa_ctx *ec_ctx = NULL;
+    int ret;
+
+    if (abstract != NULL && *abstract) {
+        hostkey_method_ssh_ecdsa_dtor(session, abstract);
+        *abstract = NULL;
+    }
+
+    ret = _libssh2_ecdsa_new_private(&ec_ctx, session, privkeyfile, passphrase);
+
+    if ( abstract != NULL )
+        *abstract = ec_ctx;
+
+    return ret;
+}
+
+/*
+ * hostkey_method_ssh_ecdsa_initPEMFromMemory
+ *
+ * Load a Private Key from memory
+ */
+static int
+hostkey_method_ssh_ecdsa_initPEMFromMemory(LIBSSH2_SESSION * session,
+                                         const char *privkeyfiledata,
+                                         size_t privkeyfiledata_len,
+                                         unsigned const char *passphrase,
+                                         void **abstract)
+{
+    libssh2_ecdsa_ctx *ec_ctx = NULL;
+    int ret;
+
+    if (abstract != NULL && *abstract) {
+        hostkey_method_ssh_ecdsa_dtor(session, abstract);
+        *abstract = NULL;
+    }
+
+    ret = _libssh2_ecdsa_new_private_frommemory(&ec_ctx, session,
+                                                privkeyfiledata,
+                                                privkeyfiledata_len, passphrase);
+    if (ret) {
+        return -1;
+    }
+
+    if (abstract != NULL)
+        *abstract = ec_ctx;
+
+    return 0;
+}
+
+/*
+ * hostkey_method_ecdsa_sig_verify
+ *
+ * Verify signature created by remote
+ */
+static int
+hostkey_method_ssh_ecdsa_sig_verify(LIBSSH2_SESSION * session,
+                                    const unsigned char *sig,
+                                    size_t sig_len,
+                                    const unsigned char *m,
+                                    size_t m_len, void **abstract)
+{
+    const unsigned char *r, *s, *p;
+    size_t r_len, s_len;
+    libssh2_ecdsa_ctx *ctx = (libssh2_ecdsa_ctx *) (*abstract);
+
+    (void) session;
+
+    if ( sig_len < 35 )
+        return -1;
+
+    /* Skip past keyname_len(4) + keyname(19){"ecdsa-sha2-nistp256"} + signature_len(4) */
+    p = sig;
+    p += 27;
+
+    r_len = _libssh2_ntohu32(p);
+    p += 4;
+    r = p;
+    p += r_len;
+
+    s_len = _libssh2_ntohu32(p);
+    p += 4;
+    s = p;
+
+    return _libssh2_ecdsa_verify(ctx, r, r_len, s, s_len, m, m_len);
+}
+
+
+#define LIBSSH2_HOSTKEY_METHOD_EC_SIGNV_HASH(digest_type)                                   \
+{                                                                                           \
+    unsigned char hash[SHA##digest_type##_DIGEST_LENGTH];                                   \
+    libssh2_sha##digest_type##_ctx ctx;                                                     \
+    int i;                                                                                  \
+    libssh2_sha##digest_type##_init(&ctx);                                                  \
+    for(i = 0; i < veccount; i++) {                                                         \
+        libssh2_sha##digest_type##_update(ctx, datavec[i].iov_base, datavec[i].iov_len);    \
+    }                                                                                       \
+    libssh2_sha##digest_type##_final(ctx, hash);                                            \
+    ret = _libssh2_ecdsa_sign(session, ec_ctx, hash, SHA##digest_type##_DIGEST_LENGTH,      \
+                                    signature, signature_len);                              \
+}
+
+
+/*
+ * hostkey_method_ecdsa_signv
+ *
+ * Construct a signature from an array of vectors
+ */
+static int
+hostkey_method_ssh_ecdsa_signv(LIBSSH2_SESSION * session,
+                               unsigned char **signature,
+                               size_t *signature_len,
+                               int veccount,
+                               const struct iovec datavec[],
+                               void **abstract)
+{
+    libssh2_ecdsa_ctx *ec_ctx = (libssh2_ecdsa_ctx *) (*abstract);
+    libssh2_curve_type type = _libssh2_ecdsa_key_get_curve_type(ec_ctx);
+    int ret = 0;
+
+    if ( type == LIBSSH2_EC_CURVE_NISTP256 ) {
+        LIBSSH2_HOSTKEY_METHOD_EC_SIGNV_HASH(256);
+    }else if ( type == LIBSSH2_EC_CURVE_NISTP384 ) {
+        LIBSSH2_HOSTKEY_METHOD_EC_SIGNV_HASH(384);
+    }else if ( type == LIBSSH2_EC_CURVE_NISTP521 ){
+        LIBSSH2_HOSTKEY_METHOD_EC_SIGNV_HASH(512);
+    }else{
+        return -1;
+    }
+
+    return ret;
+}
+
+/*
+ * hostkey_method_ssh_ecdsa_dtor
+ *
+ * Shutdown the hostkey by freeing EC_KEY context
+ */
+static int
+hostkey_method_ssh_ecdsa_dtor(LIBSSH2_SESSION * session, void **abstract)
+{
+    libssh2_ecdsa_ctx *keyctx = (libssh2_ecdsa_ctx *) (*abstract);
+    (void) session;
+
+    if (keyctx != NULL)
+        _libssh2_ecdsa_free(keyctx);
+
+    *abstract = NULL;
+
+    return 0;
+}
+
+static const LIBSSH2_HOSTKEY_METHOD hostkey_method_ecdsa_ssh_nistp256 = {
+    "ecdsa-sha2-nistp256",
+    SHA256_DIGEST_LENGTH,
+    hostkey_method_ssh_ecdsa_init,
+    hostkey_method_ssh_ecdsa_initPEM,
+    hostkey_method_ssh_ecdsa_initPEMFromMemory,
+    hostkey_method_ssh_ecdsa_sig_verify,
+    hostkey_method_ssh_ecdsa_signv,
+    NULL,                       /* encrypt */
+    hostkey_method_ssh_ecdsa_dtor,
+};
+
+static const LIBSSH2_HOSTKEY_METHOD hostkey_method_ecdsa_ssh_nistp384 = {
+    "ecdsa-sha2-nistp384",
+    SHA384_DIGEST_LENGTH,
+    hostkey_method_ssh_ecdsa_init,
+    hostkey_method_ssh_ecdsa_initPEM,
+    hostkey_method_ssh_ecdsa_initPEMFromMemory,
+    hostkey_method_ssh_ecdsa_sig_verify,
+    hostkey_method_ssh_ecdsa_signv,
+    NULL,                       /* encrypt */
+    hostkey_method_ssh_ecdsa_dtor,
+};
+
+static const LIBSSH2_HOSTKEY_METHOD hostkey_method_ecdsa_ssh_nistp521 = {
+    "ecdsa-sha2-nistp521",
+    SHA512_DIGEST_LENGTH,
+    hostkey_method_ssh_ecdsa_init,
+    hostkey_method_ssh_ecdsa_initPEM,
+    hostkey_method_ssh_ecdsa_initPEMFromMemory,
+    hostkey_method_ssh_ecdsa_sig_verify,
+    hostkey_method_ssh_ecdsa_signv,
+    NULL,                       /* encrypt */
+    hostkey_method_ssh_ecdsa_dtor,
+};
+#endif /* LIBSSH2_ECDSA */
+
+
 static const LIBSSH2_HOSTKEY_METHOD *hostkey_methods[] = {
+#if LIBSSH2_ECDSA
+    &hostkey_method_ecdsa_ssh_nistp256,
+    &hostkey_method_ecdsa_ssh_nistp384,
+    &hostkey_method_ecdsa_ssh_nistp521,
+#endif
 #if LIBSSH2_RSA
     &hostkey_method_ssh_rsa,
 #endif /* LIBSSH2_RSA */
@@ -505,7 +794,7 @@ libssh2_hostkey_methods(void)
  * Returns hash signature
  * Returned buffer should NOT be freed
  * Length of buffer is determined by hash type
- * i.e. MD5 == 16, SHA1 == 20
+ * i.e. MD5 == 16, SHA1 == 20, SHA256 == 32
  */
 LIBSSH2_API const char *
 libssh2_hostkey_hash(LIBSSH2_SESSION * session, int hash_type)
@@ -523,6 +812,11 @@ libssh2_hostkey_hash(LIBSSH2_SESSION * s
           ? (char *) session->server_hostkey_sha1
           : NULL;
         break;
+    case LIBSSH2_HOSTKEY_HASH_SHA256:
+        return (session->server_hostkey_sha256_valid)
+          ? (char *) session->server_hostkey_sha256
+          : NULL;
+        break;
     default:
         return NULL;
     }
@@ -536,6 +830,15 @@ static int hostkey_type(const unsigned c
     const unsigned char dss[] = {
         0, 0, 0, 0x07, 's', 's', 'h', '-', 'd', 's', 's'
     };
+    const unsigned char ecdsa_256[] = {
+        0, 0, 0, 0x13, 'e', 'c', 'd', 's', 'a', '-', 's', 'h', 'a', '2', '-', 'n', 'i', 's', 't', 'p', '2', '5', '6'
+    };
+    const unsigned char ecdsa_384[] = {
+        0, 0, 0, 0x13, 'e', 'c', 'd', 's', 'a', '-', 's', 'h', 'a', '2', '-', 'n', 'i', 's', 't', 'p', '3', '8', '4'
+    };
+    const unsigned char ecdsa_521[] = {
+        0, 0, 0, 0x13, 'e', 'c', 'd', 's', 'a', '-', 's', 'h', 'a', '2', '-', 'n', 'i', 's', 't', 'p', '5', '2', '1'
+    };
 
     if (len < 11)
         return LIBSSH2_HOSTKEY_TYPE_UNKNOWN;
@@ -546,6 +849,21 @@ static int hostkey_type(const unsigned c
     if (!memcmp(dss, hostkey, 11))
         return LIBSSH2_HOSTKEY_TYPE_DSS;
 
+    if ( len < 15 )
+        return LIBSSH2_HOSTKEY_TYPE_UNKNOWN;
+
+    if ( len < 23 )
+        return LIBSSH2_HOSTKEY_TYPE_UNKNOWN;
+
+    if(!memcmp(ecdsa_256, hostkey, 23))
+        return LIBSSH2_HOSTKEY_TYPE_ECDSA_256;
+
+    if(!memcmp(ecdsa_384, hostkey, 23))
+        return LIBSSH2_HOSTKEY_TYPE_ECDSA_384;
+
+    if(!memcmp(ecdsa_521, hostkey, 23))
+        return LIBSSH2_HOSTKEY_TYPE_ECDSA_521;
+
     return LIBSSH2_HOSTKEY_TYPE_UNKNOWN;
 }
 
@@ -570,4 +888,3 @@ libssh2_session_hostkey(LIBSSH2_SESSION 
         *len = 0;
     return NULL;
 }
-
