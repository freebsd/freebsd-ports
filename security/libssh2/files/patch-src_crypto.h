--- src/crypto.h.orig	2016-10-17 14:28:29 UTC
+++ src/crypto.h
@@ -120,6 +120,53 @@ int _libssh2_dsa_new_private_frommemory(
                                         unsigned const char *passphrase);
 #endif
 
+#if LIBSSH2_ECDSA
+int
+_libssh2_ecdsa_curve_name_with_octal_new(libssh2_ecdsa_ctx ** ecdsactx,
+                                         const unsigned char *k,
+                                         size_t k_len, libssh2_curve_type type);
+int
+_libssh2_ecdsa_new_private(libssh2_ecdsa_ctx ** ec_ctx,
+                           LIBSSH2_SESSION * session,
+                           const char *filename, unsigned const char *passphrase);
+
+int _libssh2_ecdsa_new_openssh_private(libssh2_ecdsa_ctx ** dsa,
+                                       LIBSSH2_SESSION * session,
+                                       const char *filename,
+                                       unsigned const char *passphrase);
+int
+_libssh2_ecdsa_verify(libssh2_ecdsa_ctx * ctx,
+                      const unsigned char *r, size_t r_len,
+                      const unsigned char *s, size_t s_len,
+                      const unsigned char *m, size_t m_len);
+
+int
+_libssh2_ecdsa_create_key(_libssh2_ec_key **out_private_key,
+                          unsigned char **out_public_key_octal,
+                          size_t *out_public_key_octal_len, libssh2_curve_type curve_type);
+
+int
+_libssh2_ecdh_gen_k(_libssh2_bn **k, _libssh2_ec_key *private_key,
+                    const unsigned char *server_public_key, size_t server_public_key_len);
+
+int
+_libssh2_ecdsa_sign(LIBSSH2_SESSION *session, libssh2_ecdsa_ctx *ec_ctx,
+                    const unsigned char *hash, unsigned long hash_len,
+                    unsigned char **signature, size_t *signature_len);
+
+int _libssh2_ecdsa_new_private_frommemory(libssh2_ecdsa_ctx ** ec_ctx,
+                                        LIBSSH2_SESSION * session,
+                                        const char *filedata, size_t filedata_len,
+                                        unsigned const char *passphrase);
+
+libssh2_curve_type
+_libssh2_ecdsa_key_get_curve_type(_libssh2_ec_key *key);
+
+int
+_libssh2_ecdsa_curve_type_from_name(const char *name, libssh2_curve_type *out_type);
+
+#endif /* LIBSSH2_ECDSA */
+
 int _libssh2_cipher_init(_libssh2_cipher_ctx * h,
                          _libssh2_cipher_type(algo),
                          unsigned char *iv,
