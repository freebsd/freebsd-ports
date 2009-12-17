--- gcr/gcr-certificate.c.orig	2009-12-16 23:36:19.000000000 -0500
+++ gcr/gcr-certificate.c	2009-12-16 23:36:28.000000000 -0500
@@ -156,7 +156,7 @@ calculate_key_size (GcrCertificateInfo *
 	const guchar *data, *params;
 	gsize n_data, n_params, n_key;
 	guint key_size = 0;
-	guchar *key;
+	guchar *key = NULL;
 	GQuark oid;
 	
 	data = egg_asn1_read_element (info->asn1, info->der, info->n_der, "tbsCertificate.subjectPublicKeyInfo", &n_data);
