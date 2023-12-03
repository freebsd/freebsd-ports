--- SSLeay.xs.orig	2022-01-10 19:05:48 UTC
+++ SSLeay.xs
@@ -685,7 +685,6 @@ static int ssleay_ctx_passwd_cb_invoke(char *buf, int 
 }
 
 #if OPENSSL_VERSION_NUMBER >= 0x1010006fL /* In OpenSSL 1.1.0 but actually called for $ssl from 1.1.0f */
-#ifndef LIBRESSL_VERSION_NUMBER
 #ifndef OPENSSL_IS_BORINGSSL
 static int ssleay_ssl_passwd_cb_invoke(char *buf, int size, int rwflag, void *userdata)
 {
@@ -732,7 +731,6 @@ static int ssleay_ssl_passwd_cb_invoke(char *buf, int 
     return strlen(buf);
 }
 #endif /* !BoringSSL */
-#endif /* !LibreSSL */
 #endif /* >= 1.1.0f */
 
 int ssleay_ctx_cert_verify_cb_invoke(X509_STORE_CTX* x509_store_ctx, void* data)
@@ -1138,7 +1136,7 @@ int next_proto_helper_protodata2AV(AV * list, const un
 
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10001000L && !defined(OPENSSL_NO_NEXTPROTONEG) && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10001000L && !defined(OPENSSL_NO_NEXTPROTONEG)
 
 int next_proto_select_cb_invoke(SSL *ssl, unsigned char **out, unsigned char *outlen,
                                 const unsigned char *in, unsigned int inlen, void *arg)
@@ -1767,7 +1765,7 @@ int ossl_provider_do_all_cb_invoke(OSSL_PROVIDER *prov
 }
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101001 && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10101001
 void ssl_ctx_keylog_cb_func_invoke(const SSL *ssl, const char *line)
 {
     dSP;
@@ -2009,7 +2007,7 @@ const char *
 SSLeay_version(type=SSLEAY_VERSION)
         int type
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 
 unsigned long
 OpenSSL_version_num()
@@ -2180,7 +2178,7 @@ SSL_CTX_set_verify(ctx,mode,callback=&PL_sv_undef)
         SSL_CTX_set_verify(ctx, mode, &ssleay_verify_callback_invoke);
     }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100001L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100001L
 
 void
 SSL_CTX_set_security_level(SSL_CTX * ctx, int level)
@@ -2190,7 +2188,7 @@ SSL_CTX_get_security_level(SSL_CTX * ctx)
 
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101007L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10101007L
 
 int
 SSL_CTX_set_num_tickets(SSL_CTX *ctx, size_t num_tickets)
@@ -2200,14 +2198,14 @@ SSL_CTX_get_num_tickets(SSL_CTX *ctx)
 
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101003L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10101003L
 
 int
 SSL_CTX_set_ciphersuites(SSL_CTX *ctx, const char *str)
 
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010100fL && !defined(LIBRESSL_VERSION_NUMBER) /* OpenSSL 1.1.1 */
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
 
 void
 SSL_CTX_set_post_handshake_auth(SSL_CTX *ctx, int val)
@@ -2395,7 +2393,7 @@ SSL_peek(s,max=32768)
 	}
 	Safefree(buf);
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010100fL && !defined(LIBRESSL_VERSION_NUMBER) /* OpenSSL 1.1.1 */
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
 
 void
 SSL_read_ex(s,max=32768)
@@ -2631,7 +2629,7 @@ int
 SSL_pending(s)
      SSL *              s
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL && !defined(LIBRESSL_VERSION_NUMBER) /* OpenSSL 1.1.0 */
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
 
 int
 SSL_has_pending(s)
@@ -2750,7 +2748,7 @@ void
 SSL_SESSION_free(ses)
      SSL_SESSION *      ses
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101001L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10101001L
 
 int
 SSL_SESSION_is_resumable(ses)
@@ -2761,7 +2759,7 @@ SSL_SESSION_dup(sess)
      SSL_SESSION * sess
 
 #endif
-#if OPENSSL_VERSION_NUMBER >= 0x1010100fL && !defined(LIBRESSL_VERSION_NUMBER) /* OpenSSL 1.1.1 */
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
 
 void
 SSL_set_post_handshake_auth(SSL *ssl, int val)
@@ -2800,7 +2798,7 @@ d2i_SSL_SESSION(pv)
     OUTPUT:
 	RETVAL
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10100004L && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL)
+#if OPENSSL_VERSION_NUMBER >= 0x10100004L
 
 int
 SSL_SESSION_up_ref(sess)
@@ -3081,7 +3079,6 @@ SSL_CTX_set_tlsext_servername_callback(ctx,callback=&P
 #endif
 
 #if OPENSSL_VERSION_NUMBER >= 0x1010006fL /* In OpenSSL 1.1.0 but actually called for $ssl starting from 1.1.0f */
-#ifndef LIBRESSL_VERSION_NUMBER
 #ifndef OPENSSL_IS_BORINGSSL
 void
 SSL_set_default_passwd_cb(ssl,callback=&PL_sv_undef)
@@ -3113,10 +3110,9 @@ SSL_set_default_passwd_cb_userdata(ssl,data=&PL_sv_und
         }
 
 #endif /* !BoringSSL */
-#endif /* !LibreSSL */
 #endif /* >= 1.1.0f */
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100001L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100001L
 
 void
 SSL_set_security_level(SSL * ssl, int level)
@@ -3126,7 +3122,7 @@ SSL_get_security_level(SSL * ssl)
 
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101007L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10101007L
 
 int
 SSL_set_num_tickets(SSL *ssl, size_t num_tickets)
@@ -3136,7 +3132,7 @@ SSL_get_num_tickets(SSL *ssl)
 
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101003L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10101003L
 
 int
 SSL_set_ciphersuites(SSL *ssl, const char *str)
@@ -3270,7 +3266,7 @@ RAND_bytes(buf, num)
     OUTPUT:
         RETVAL
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101001L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10101001L
 
 int
 RAND_priv_bytes(buf, num)
@@ -3361,7 +3357,7 @@ RAND_write_file(file_name)
 
 #define REM40 "Minimal X509 stuff..., this is a bit ugly and should be put in its own modules Net::SSLeay::X509.pm"
 
-#if (OPENSSL_VERSION_NUMBER >= 0x1000200fL && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2050000fL)
+#if OPENSSL_VERSION_NUMBER >= 0x1000200fL
 
 int
 X509_check_host(X509 *cert, const char *name, unsigned int flags = 0, SV *peername = &PL_sv_undef)
@@ -3465,7 +3461,7 @@ X509_get_pubkey(X509 *x)
 ASN1_INTEGER *
 X509_get_serialNumber(X509 *x)
 
-#if (OPENSSL_VERSION_NUMBER >= 0x1010000fL && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2080100fL)
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
 
 const ASN1_INTEGER *
 X509_get0_serialNumber(const X509 *x)
@@ -3952,7 +3948,7 @@ X509 *
 X509_STORE_CTX_get_current_cert(x509_store_ctx)
      X509_STORE_CTX * 	x509_store_ctx
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10100005L && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL) /* OpenSSL 1.1.0-pre5, LibreSSL 2.7.0 */
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
 
 X509 *
 X509_STORE_CTX_get0_cert(x509_store_ctx)
@@ -5063,7 +5059,7 @@ TLSv1_2_client_method()
 #endif
 
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x20020002L)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 
 const SSL_METHOD *
 TLS_method()
@@ -5077,7 +5073,7 @@ TLS_client_method()
 #endif /* OpenSSL 1.1.0 or LibreSSL 2.2.2 */
 
 
-#if  (OPENSSL_VERSION_NUMBER >= 0x10100002L && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2060000fL)
+#if  OPENSSL_VERSION_NUMBER >= 0x10100002L
 
 int
 SSL_CTX_set_min_proto_version(ctx, version)
@@ -5102,7 +5098,7 @@ SSL_set_max_proto_version(ssl, version)
 #endif /* OpenSSL 1.1.0-pre2 or LibreSSL 2.6.0 */
 
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010007fL && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x1010007fL
 
 int
 SSL_CTX_get_min_proto_version(ctx)
@@ -5451,7 +5447,7 @@ SSL_CTX_use_certificate_chain_file(ctx,file)
      const char * file
 
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 
 int
 SSL_use_certificate_chain_file(ssl,file)
@@ -5698,7 +5694,7 @@ SSL_CTX_set_msg_callback(ctx,callback,data=&PL_sv_unde
         }
 
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101001 && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10101001
 
 void
 SSL_CTX_set_keylog_callback(SSL_CTX *ctx, SV *callback)
@@ -5766,7 +5762,7 @@ int
 SSL_version(ssl)
      SSL *	ssl
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100006L && !defined(LIBRESSL_VERSION_NUMBER) /* 1.1.0-pre6 */
+#if OPENSSL_VERSION_NUMBER >= 0x10100006L
 
 int
 SSL_client_version(ssl)
@@ -6231,7 +6227,7 @@ RSA_generate_key(bits,ee,perl_cb=&PL_sv_undef,perl_dat
 	   BN_free(e);
            croak("Net::SSLeay: RSA_generate_key perl function could not create RSA structure.\n");
        }
-#if (OPENSSL_VERSION_NUMBER >= 0x10100001L && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL)
+#if OPENSSL_VERSION_NUMBER >= 0x10100001L
        BN_GENCB *new_cb;
        new_cb = BN_GENCB_new();
        if(!new_cb) {
@@ -6278,7 +6274,7 @@ RSA_generate_key(bits,e,perl_cb=&PL_sv_undef,perl_data
 
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 
 void
 RSA_get_key_parameters(rsa)
@@ -6449,7 +6445,7 @@ SSL_total_renegotiations(ssl)
   OUTPUT:
   RETVAL
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 void
 SSL_SESSION_get_master_key(s)
      SSL_SESSION *   s
@@ -6489,7 +6485,7 @@ SSL_SESSION_set_master_key(s,key)
 
 #endif
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 
 void
 SSL_get_client_random(s)
@@ -6516,7 +6512,7 @@ SSL_get_client_random(s)
 
 #endif
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 
 void
 SSL_get_server_random(s)
@@ -6547,7 +6543,7 @@ int
 SSL_get_keyblock_size(s)
      SSL *   s
      CODE:
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
         const SSL_CIPHER *ssl_cipher;
 	int cipher = NID_undef, digest = NID_undef, mac_secret_size = 0;
 	const EVP_CIPHER *c = NULL;
@@ -6932,7 +6928,7 @@ X509_VERIFY_PARAM_lookup(name)
 void
 X509_VERIFY_PARAM_table_cleanup()
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10002001L && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL) /* OpenSSL 1.0.2-beta1, LibreSSL 2.7.0 */
+#if OPENSSL_VERSION_NUMBER >= 0x10002001L
 
 X509_VERIFY_PARAM *
 SSL_CTX_get0_param(ctx)
@@ -6985,7 +6981,7 @@ X509_VERIFY_PARAM_set1_ip_asc(param, ipasc)
 
 #endif /* OpenSSL 1.0.2-beta1, LibreSSL 2.7.0 */
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10002002L && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL) /* OpenSSL 1.0.2-beta2, LibreSSL 2.7.0 */
+#if OPENSSL_VERSION_NUMBER >= 0x10002002L
 
 int
 X509_VERIFY_PARAM_add1_host(param, name)
@@ -7010,6 +7006,7 @@ X509_VERIFY_PARAM_get0_peername(param)
 
 #endif /* OpenSSL 1.0.2-beta2, LibreSSL 2.7.0 */
 
+#if !defined(LIBRESSL_VERSION_NUMBER) || (LIBRESSL_VERSION_NUMBER < 0x3080000fL) /* LibreSSL < 3.8.0 */
 void
 X509_policy_tree_free(tree)
     X509_POLICY_TREE *tree
@@ -7052,6 +7049,7 @@ const X509_POLICY_NODE *
 X509_policy_node_get0_parent(node)
     const X509_POLICY_NODE *node
 
+#endif /* !(LibreSSL >= 3.8.0) */
 #endif
 
 ASN1_OBJECT *
@@ -7197,7 +7195,7 @@ ASN1_OBJECT *
 P_X509_get_signature_alg(x)
         X509 * x
     CODE:
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
         RETVAL = (X509_get0_tbs_sigalg(x)->algorithm);
 #else
         RETVAL = (x->cert_info->signature->algorithm);
@@ -7239,7 +7237,7 @@ X509_get_X509_PUBKEY(x)
    XPUSHs(sv_2mortal(newSVpv((char*)pc,len)));
    Safefree(pc);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10001000L && !defined(OPENSSL_NO_NEXTPROTONEG) && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10001000L && !defined(OPENSSL_NO_NEXTPROTONEG)
 
 int
 SSL_CTX_set_next_protos_advertised_cb(ctx,callback,data=&PL_sv_undef)
@@ -7690,7 +7688,7 @@ OCSP_response_results(rsp,...)
 		if (!idsv) {
 		    /* getall: create new SV with OCSP_CERTID */
 		    unsigned char *pi,*pc;
-#if OPENSSL_VERSION_NUMBER >= 0x10100003L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100003L
 		    int len = i2d_OCSP_CERTID((OCSP_CERTID *)OCSP_SINGLERESP_get0_id(sir),NULL);
 #else
 		    int len = i2d_OCSP_CERTID(sir->certId,NULL);
@@ -7699,7 +7697,7 @@ OCSP_response_results(rsp,...)
 		    Newx(pc,len,unsigned char);
 		    if (!pc) croak("out of memory");
 		    pi = pc;
-#if OPENSSL_VERSION_NUMBER >= 0x10100003L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100003L
 		    i2d_OCSP_CERTID((OCSP_CERTID *)OCSP_SINGLERESP_get0_id(sir),&pi);
 #else
 		    i2d_OCSP_CERTID(sir->certId,&pi);
