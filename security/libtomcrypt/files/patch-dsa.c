--- dsa.c.orig	Tue Jan 13 14:52:15 2004
+++ dsa.c	Tue Jan 13 14:53:54 2004
@@ -297,15 +297,15 @@
    return err;
 }
 
-#define OUTPUT_BIGNUM(num, buf2, y, z)         \
-{                                              \
-      z = (unsigned long)mp_unsigned_bin_size(num);  \
-      if ((y + 4 + z) > *outlen) { return CRYPT_BUFFER_OVERFLOW; } \
-      STORE32L(z, out+y);                     \
-      y += 4;                                  \
-      if (mp_to_unsigned_bin(num, out+y) != MP_OKAY) { return CRYPT_MEM; }  \
-      y += z;                                  \
-}
+#define OUTPUT_BIGNUM(num, buf2, y, z)         \
+{                                              \
+      z = (unsigned long)mp_unsigned_bin_size(num);  \
+      if ((y + 4 + z) > *outlen) { return CRYPT_BUFFER_OVERFLOW; } \
+      STORE32L(z, out+y);                     \
+      y += 4;                                  \
+      if (mp_to_unsigned_bin(num, out+y) != MP_OKAY) { return CRYPT_MEM; }  \
+      y += z;                                  \
+}
 
 int dsa_export(unsigned char *out, unsigned long *outlen, int type, dsa_key *key)
 {
@@ -352,33 +352,33 @@
    return CRYPT_OK;
 }
 
-#define INPUT_BIGNUM(num, in, x, y)                              \
-{                                                                \
-     /* load value */                                            \
-     if (y+4 > inlen) {                                          \
-        err = CRYPT_INVALID_PACKET;                              \
-        goto error;                                              \
-     }                                                           \
-     LOAD32L(x, in+y);                                           \
-     y += 4;                                                     \
-                                                                 \
-     /* sanity check... */                                       \
-     if (y+x > inlen) {                                          \
-        err = CRYPT_INVALID_PACKET;                              \
-        goto error;                                              \
-     }                                                           \
-                                                                 \
-     /* load it */                                               \
-     if (mp_read_unsigned_bin(num, (unsigned char *)in+y, (int)x) != MP_OKAY) {\
-        err = CRYPT_MEM;                                         \
-        goto error;                                              \
-     }                                                           \
-     y += x;                                                     \
-     if (mp_shrink(num) != MP_OKAY) {                            \
-        err = CRYPT_MEM;                                         \
-        goto error;                                              \
-     }                                                           \
-}
+#define INPUT_BIGNUM(num, in, x, y)                              \
+{                                                                \
+     /* load value */                                            \
+     if (y+4 > inlen) {                                          \
+        err = CRYPT_INVALID_PACKET;                              \
+        goto error;                                              \
+     }                                                           \
+     LOAD32L(x, in+y);                                           \
+     y += 4;                                                     \
+                                                                 \
+     /* sanity check... */                                       \
+     if (y+x > inlen) {                                          \
+        err = CRYPT_INVALID_PACKET;                              \
+        goto error;                                              \
+     }                                                           \
+                                                                 \
+     /* load it */                                               \
+     if (mp_read_unsigned_bin(num, (unsigned char *)in+y, (int)x) != MP_OKAY) {\
+        err = CRYPT_MEM;                                         \
+        goto error;                                              \
+     }                                                           \
+     y += x;                                                     \
+     if (mp_shrink(num) != MP_OKAY) {                            \
+        err = CRYPT_MEM;                                         \
+        goto error;                                              \
+     }                                                           \
+}
 
 int dsa_import(const unsigned char *in, unsigned long inlen, dsa_key *key)
 {
