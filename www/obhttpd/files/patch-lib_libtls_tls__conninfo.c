--- lib/libtls/tls_conninfo.c.orig	2017-05-04 18:48:54 UTC
+++ lib/libtls/tls_conninfo.c
@@ -140,9 +140,9 @@ tls_get_peer_cert_times(struct tls *ctx,
 		goto err;
 	if ((after = X509_get_notAfter(ctx->ssl_peer_cert)) == NULL)
 		goto err;
-	if (asn1_time_parse(before->data, before->length, &before_tm, 0) == -1)
+	if (ASN1_time_parse(before->data, before->length, &before_tm, 0) == -1)
 		goto err;
-	if (asn1_time_parse(after->data, after->length, &after_tm, 0) == -1)
+	if (ASN1_time_parse(after->data, after->length, &after_tm, 0) == -1)
 		goto err;
 	if ((*notbefore = timegm(&before_tm)) == -1)
 		goto err;
