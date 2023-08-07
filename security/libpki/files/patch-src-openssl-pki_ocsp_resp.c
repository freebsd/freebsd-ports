--- src/openssl/pki_ocsp_resp.c.orig	2023-06-27 08:58:28.486438000 +0200
+++ src/openssl/pki_ocsp_resp.c	2023-06-27 13:17:52.661387000 +0200
@@ -701,7 +701,10 @@
 				PKI_ERROR(PKI_ERR_MEMORY_ALLOC, NULL );
 				break;
 			}
-#if OPENSSL_VERSION_NUMBER > 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+			mem->size = (size_t)ASN1_item_i2d((void *)&(tmp_x->tbsResponseData),
+				&(mem->data), (ASN1_ITEM *) OCSP_RESPDATA_it );
+#elif OPENSSL_VERSION_NUMBER > 0x1010000fL
 			mem->size = (size_t)ASN1_item_i2d((void *)&(tmp_x->tbsResponseData),
 				&(mem->data), &OCSP_RESPDATA_it );
 #else
