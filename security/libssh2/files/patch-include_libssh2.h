--- include/libssh2.h.orig	2016-10-25 06:44:34 UTC
+++ include/libssh2.h
@@ -403,11 +403,15 @@ typedef struct _LIBSSH2_POLLFD {
 /* Hash Types */
 #define LIBSSH2_HOSTKEY_HASH_MD5                            1
 #define LIBSSH2_HOSTKEY_HASH_SHA1                           2
+#define LIBSSH2_HOSTKEY_HASH_SHA256                         3
 
 /* Hostkey Types */
-#define LIBSSH2_HOSTKEY_TYPE_UNKNOWN			    0
-#define LIBSSH2_HOSTKEY_TYPE_RSA			    1
-#define LIBSSH2_HOSTKEY_TYPE_DSS			    2
+#define LIBSSH2_HOSTKEY_TYPE_UNKNOWN            0
+#define LIBSSH2_HOSTKEY_TYPE_RSA                1
+#define LIBSSH2_HOSTKEY_TYPE_DSS                2
+#define LIBSSH2_HOSTKEY_TYPE_ECDSA_256          3
+#define LIBSSH2_HOSTKEY_TYPE_ECDSA_384          4
+#define LIBSSH2_HOSTKEY_TYPE_ECDSA_521          5
 
 /* Disconnect Codes (defined by SSH protocol) */
 #define SSH_DISCONNECT_HOST_NOT_ALLOWED_TO_CONNECT          1
@@ -960,12 +964,15 @@ libssh2_knownhost_init(LIBSSH2_SESSION *
 #define LIBSSH2_KNOWNHOST_KEYENC_BASE64   (2<<16)
 
 /* type of key (2 bits) */
-#define LIBSSH2_KNOWNHOST_KEY_MASK     (7<<18)
-#define LIBSSH2_KNOWNHOST_KEY_SHIFT    18
-#define LIBSSH2_KNOWNHOST_KEY_RSA1     (1<<18)
-#define LIBSSH2_KNOWNHOST_KEY_SSHRSA   (2<<18)
-#define LIBSSH2_KNOWNHOST_KEY_SSHDSS   (3<<18)
-#define LIBSSH2_KNOWNHOST_KEY_UNKNOWN  (7<<18)
+#define LIBSSH2_KNOWNHOST_KEY_MASK         (7<<18)
+#define LIBSSH2_KNOWNHOST_KEY_SHIFT        18
+#define LIBSSH2_KNOWNHOST_KEY_RSA1         (1<<18)
+#define LIBSSH2_KNOWNHOST_KEY_SSHRSA       (2<<18)
+#define LIBSSH2_KNOWNHOST_KEY_SSHDSS       (3<<18)
+#define LIBSSH2_KNOWNHOST_KEY_ECDSA_256    (4<<18)
+#define LIBSSH2_KNOWNHOST_KEY_ECDSA_384    (5<<18)
+#define LIBSSH2_KNOWNHOST_KEY_ECDSA_521    (6<<18)
+#define LIBSSH2_KNOWNHOST_KEY_UNKNOWN      (7<<18)
 
 LIBSSH2_API int
 libssh2_knownhost_add(LIBSSH2_KNOWNHOSTS *hosts,
