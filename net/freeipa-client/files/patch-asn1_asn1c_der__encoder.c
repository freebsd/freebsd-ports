--- asn1/asn1c/der_encoder.c.orig	2024-08-21 15:06:37 UTC
+++ asn1/asn1c/der_encoder.c
@@ -4,6 +4,7 @@
  */
 #include <asn_internal.h>
 #include <errno.h>
+#include <stdlib.h>
 
 static ssize_t der_write_TL(ber_tlv_tag_t tag, ber_tlv_len_t len,
 	asn_app_consume_bytes_f *cb, void *app_key, int constructed);
