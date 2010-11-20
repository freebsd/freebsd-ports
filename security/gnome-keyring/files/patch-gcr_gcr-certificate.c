--- gcr/gcr-certificate.c.orig	2010-09-04 12:04:30.000000000 +0200
+++ gcr/gcr-certificate.c	2010-09-04 12:04:42.000000000 +0200
@@ -158,7 +158,7 @@ calculate_key_size (GcrCertificateInfo *
 	const guchar *data, *params;
 	gsize n_data, n_params;
 	guint key_size = 0, n_bits;
-	guchar *key;
+	guchar *key = NULL;
 	GQuark oid;
 
 	data = egg_asn1x_get_raw_element (egg_asn1x_node (info->asn1, "tbsCertificate", "subjectPublicKeyInfo", NULL), &n_data);
