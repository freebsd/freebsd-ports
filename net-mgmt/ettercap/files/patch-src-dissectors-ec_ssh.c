Obtained from:	https://github.com/LocutusOfBorg/ettercap/commit/f0d63b27c82df2ad5f7ada6310727d841b43fbcc

--- src/dissectors/ec_ssh.c.orig	2015-03-14 13:43:11 UTC
+++ src/dissectors/ec_ssh.c
@@ -36,6 +36,10 @@
 #include <openssl/md5.h>
 #include <zlib.h>
 
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#define HAVE_OPAQUE_RSA_DSA_DH 1 /* since 1.1.0 -pre5 */
+#endif
+
 #define SMSG_PUBLIC_KEY 2
 #define CMSG_SESSION_KEY 3
 #define CMSG_USER 4
@@ -138,6 +142,11 @@ FUNC_DECODER(dissector_ssh)
    char tmp[MAX_ASCII_ADDR_LEN];
    u_int32 ssh_len, ssh_mod;
    u_char ssh_packet_type, *ptr, *key_to_put;
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+   BIGNUM *h_n, *s_n, *m_h_n, *m_s_n;
+   BIGNUM *h_e, *s_e, *m_h_e, *m_s_e;
+   BIGNUM *h_d, *s_d, *m_h_d, *m_s_d;
+#endif
 
    /* don't complain about unused var */
    (void) DECODE_DATA; 
@@ -383,12 +392,25 @@ FUNC_DECODER(dissector_ssh)
             if (session_data->ptrkey == NULL) { 
                /* Initialize RSA key structures (other fileds are set to 0) */
                session_data->serverkey = RSA_new();
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+               s_n = BN_new();
+               s_e = BN_new();
+               RSA_set0_key(session_data->serverkey, s_n, s_e, s_d);
+#else
                session_data->serverkey->n = BN_new();
                session_data->serverkey->e = BN_new();
+#endif
 
                session_data->hostkey = RSA_new();
+
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+               h_n = BN_new();
+               h_e = BN_new();
+               RSA_set0_key(session_data->hostkey, h_n, h_e, h_d);
+#else
                session_data->hostkey->n = BN_new();
                session_data->hostkey->e = BN_new();
+#endif
 
                /* Get the RSA Key from the packet */
                NS_GET32(server_mod,ptr);
@@ -396,19 +418,37 @@ FUNC_DECODER(dissector_ssh)
                   DEBUG_MSG("Dissector_ssh Bougs Server_Mod");
                   return NULL;
                }
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+               RSA_get0_key(session_data->serverkey, &s_n, &s_e, &s_d);
+               get_bn(s_e, &ptr);
+               get_bn(s_n, &ptr);
+#else
                get_bn(session_data->serverkey->e, &ptr);
                get_bn(session_data->serverkey->n, &ptr);
+#endif
 
                NS_GET32(host_mod,ptr);
                if (ptr + (host_mod/8) > PACKET->DATA.data + PACKET->DATA.len) {
                   DEBUG_MSG("Dissector_ssh Bougs Host_Mod");
                   return NULL;
                }
+
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+               RSA_get0_key(session_data->hostkey, &h_n, &h_e, &h_d);
+               get_bn(h_e, &ptr);
+               get_bn(h_n, &ptr);
+#else
                get_bn(session_data->hostkey->e, &ptr);
                get_bn(session_data->hostkey->n, &ptr);
+#endif
 
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+               server_exp = BN_get_word(s_e);
+               host_exp   = BN_get_word(h_e);
+#else
                server_exp = *(session_data->serverkey->e->d);
                host_exp   = *(session_data->hostkey->e->d);
+#endif
 
                /* Check if we already have a suitable RSA key to substitute */
                index_ssl = &ssh_conn_key;
@@ -424,7 +464,7 @@ FUNC_DECODER(dissector_ssh)
                   SAFE_CALLOC(*index_ssl, 1, sizeof(ssh_my_key));
 
                   /* Generate the new key */
-                  (*index_ssl)->myserverkey = (RSA *)RSA_generate_key(server_mod, server_exp, NULL, NULL);
+                  (*index_ssl)->myserverkey = (RSA *)RSA_generate_key_ex(server_mod, server_exp, NULL, NULL);
                   (*index_ssl)->myhostkey = (RSA *)RSA_generate_key(host_mod, host_exp, NULL, NULL);
                   (*index_ssl)->server_mod = server_mod;
                   (*index_ssl)->host_mod = host_mod;
@@ -443,11 +483,25 @@ FUNC_DECODER(dissector_ssh)
 
             /* Put our RSA key in the packet */
             key_to_put+=4;
+
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+            RSA_get0_key(session_data->ptrkey->myserverkey, &m_s_n, &m_s_e, &m_s_d);
+            put_bn(m_s_e, &key_to_put);
+            put_bn(m_s_n, &key_to_put);
+#else
             put_bn(session_data->ptrkey->myserverkey->e, &key_to_put);
             put_bn(session_data->ptrkey->myserverkey->n, &key_to_put);
+#endif
             key_to_put+=4;
+
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+            RSA_get0_key(session_data->ptrkey->myhostkey, &m_h_n, &m_h_e, &m_h_d);
+            put_bn(m_h_e, &key_to_put);
+            put_bn(m_h_n, &key_to_put);
+#else
             put_bn(session_data->ptrkey->myhostkey->e, &key_to_put);
             put_bn(session_data->ptrkey->myhostkey->n, &key_to_put);
+#endif
 
             /* Recalculate SSH crc */
             *(u_int32 *)(PACKET->DATA.data + PACKET->DATA.len - 4) = htonl(CRC_checksum(PACKET->DATA.data+4, PACKET->DATA.len-8, CRC_INIT_ZERO));
@@ -482,19 +536,34 @@ FUNC_DECODER(dissector_ssh)
             key_to_put = ptr;
 
             /* Calculate real session id and our fake session id */
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+            temp_session_id = ssh_session_id(cookie, h_n, s_n);
+#else
             temp_session_id = ssh_session_id(cookie, session_data->hostkey->n, session_data->serverkey->n);
+#endif
             if (temp_session_id)
                memcpy(session_id1, temp_session_id, 16);
+
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+            temp_session_id=ssh_session_id(cookie, m_h_n, m_s_n);
+#else
             temp_session_id=ssh_session_id(cookie, session_data->ptrkey->myhostkey->n, session_data->ptrkey->myserverkey->n);
+#endif
+
             if (temp_session_id)
                memcpy(session_id2, temp_session_id, 16);
 
             /* Get the session key */
             enckey = BN_new();
+
             get_bn(enckey, &ptr);
 
             /* Decrypt session key */
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+            if (BN_cmp(m_s_n, m_h_n) > 0) {
+#else
             if (BN_cmp(session_data->ptrkey->myserverkey->n, session_data->ptrkey->myhostkey->n) > 0) {
+#endif
               rsa_private_decrypt(enckey, enckey, session_data->ptrkey->myserverkey);
               rsa_private_decrypt(enckey, enckey, session_data->ptrkey->myhostkey);
             } else {
@@ -534,7 +603,11 @@ FUNC_DECODER(dissector_ssh)
                  BN_add_word(bn, sesskey[i]);
             }
 
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+            if (BN_cmp(s_n, h_n) < 0) {
+#else
             if (BN_cmp(session_data->serverkey->n, session_data->hostkey->n) < 0) {
+#endif
                rsa_public_encrypt(bn, bn, session_data->serverkey);
                rsa_public_encrypt(bn, bn, session_data->hostkey);
             } else {
@@ -716,7 +789,16 @@ static void rsa_public_encrypt(BIGNUM *o
    u_char *inbuf, *outbuf;
    int32 len, ilen, olen;
 
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+   BIGNUM *n;
+   BIGNUM *e;
+   BIGNUM *d;
+   RSA_get0_key(key, &n, &e, &d);
+   olen = BN_num_bytes(n);
+#else
    olen = BN_num_bytes(key->n);
+#endif
+
    outbuf = malloc(olen);
    if (outbuf == NULL) /* oops, couldn't allocate memory */
       return;
@@ -744,7 +826,16 @@ static void rsa_private_decrypt(BIGNUM *
    u_char *inbuf, *outbuf;
    int32 len, ilen, olen;
 
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+   BIGNUM *n;
+   BIGNUM *e;
+   BIGNUM *d;
+   RSA_get0_key(key, &n, &e, &d);
+   olen = BN_num_bytes(n);
+#else
    olen = BN_num_bytes(key->n);
+#endif
+
    outbuf = malloc(olen);
    if (outbuf == NULL) /* oops, couldn't allocate memory */
       return;
