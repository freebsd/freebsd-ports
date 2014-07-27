--- lib/gssapi/krb5/prf.c.orig	2012-01-10 21:53:51.000000000 +0000
+++ lib/gssapi/krb5/prf.c
@@ -119,7 +119,7 @@ _gsskrb5_pseudo_random(OM_uint32 *minor_
     while(dol > 0) {
 	size_t tsize;
 
-	_gsskrb5_encode_om_uint32(num, input.data);
+	_gsskrb5_encode_be_om_uint32(num, input.data);
 
 	ret = krb5_crypto_prf(context, crypto, &input, &output);
 	if (ret) {
