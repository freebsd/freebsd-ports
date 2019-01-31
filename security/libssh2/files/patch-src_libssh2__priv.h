--- src/libssh2_priv.h.orig	2016-02-24 22:44:12 UTC
+++ src/libssh2_priv.h
@@ -154,7 +154,7 @@ static inline int writev(int sock, struc
  * padding length, payload, padding, and MAC.)."
  */
 #define MAX_SSH_PACKET_LEN 35000
-#define MAX_SHA_DIGEST_LEN SHA256_DIGEST_LENGTH
+#define MAX_SHA_DIGEST_LEN SHA512_DIGEST_LENGTH
 
 #define LIBSSH2_ALLOC(session, count) \
   session->alloc((count), &(session)->abstract)
@@ -271,10 +271,13 @@ typedef struct key_exchange_state_low_t
     kmdhgGPshakex_state_t exchange_state;
     _libssh2_bn *p;             /* SSH2 defined value (p_value) */
     _libssh2_bn *g;             /* SSH2 defined value (2) */
-    unsigned char request[13];
+    unsigned char request[256]; /* Must fit EC_MAX_POINT_LEN + data */
     unsigned char *data;
     size_t request_len;
     size_t data_len;
+    _libssh2_ec_key *private_key;   /* SSH2 ecdh private key */
+    unsigned char *public_key_oct;  /* SSH2 ecdh public key octal value */
+    size_t public_key_oct_len;      /* SSH2 ecdh public key octal value length */
 } key_exchange_state_low_t;
 
 typedef struct key_exchange_state_t
@@ -609,6 +612,9 @@ struct _LIBSSH2_SESSION
     unsigned char server_hostkey_sha1[SHA_DIGEST_LENGTH];
     int server_hostkey_sha1_valid;
 
+    unsigned char server_hostkey_sha256[SHA256_DIGEST_LENGTH];
+    int server_hostkey_sha256_valid;
+
     /* (remote as source of data -- packet_read ) */
     libssh2_endpoint_data remote;
 
@@ -983,6 +989,10 @@ _libssh2_debug(LIBSSH2_SESSION * session
 #define SSH_MSG_KEX_DH_GEX_INIT                     32
 #define SSH_MSG_KEX_DH_GEX_REPLY                    33
 
+/* ecdh */
+#define SSH2_MSG_KEX_ECDH_INIT                      30
+#define SSH2_MSG_KEX_ECDH_REPLY                     31
+
 /* User Authentication */
 #define SSH_MSG_USERAUTH_REQUEST                    50
 #define SSH_MSG_USERAUTH_FAILURE                    51
