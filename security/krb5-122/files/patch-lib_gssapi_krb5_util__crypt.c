--- lib/gssapi/krb5/util_crypt.c.orig	2025-08-05 14:15:15 UTC
+++ lib/gssapi/krb5/util_crypt.c
@@ -322,12 +322,16 @@ kg_verify_checksum_v3(krb5_context context, krb5_key k
     uint8_t ckhdr[16];
     krb5_boolean valid;
 
-    /* Compose an RFC 4121 token header with EC and RRC set to 0. */
+    /*
+     * Compose an RFC 4121 token header for the checksum.  For a wrap token,
+     * the EC and RRC fields have the value 0 for the checksum operation,
+     * regardless of their values in the actual token (RFC 4121 section 4.2.4).
+     * For a MIC token, the corresponding four bytes have the value 0xFF.
+     */
     store_16_be(toktype, ckhdr);
     ckhdr[2] = flags;
     ckhdr[3] = 0xFF;
-    store_16_be(0, ckhdr + 4);
-    store_16_be(0, ckhdr + 6);
+    store_32_be((toktype == KG2_TOK_MIC_MSG) ? 0xFFFFFFFF : 0, ckhdr + 4);
     store_64_be(seqnum, ckhdr + 8);
 
     /* Verify the checksum over the data and composed header. */
