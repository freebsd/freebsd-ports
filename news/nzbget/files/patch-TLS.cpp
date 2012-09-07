--- TLS.cpp.orig	2011-06-14 23:47:22.000000000 +0200
+++ TLS.cpp	2012-08-31 09:27:41.000000000 +0200
@@ -908,7 +908,7 @@
     char *buf;
     int bufsize;
     /* needed to get the DNS subjectAltNames: */
-    STACK *subj_alt_names;
+    STACK_OF(GENERAL_NAME) *subj_alt_names;
     int subj_alt_names_count;
     GENERAL_NAME *subj_alt_name;
     /* did we find a name matching hostname? */
@@ -960,7 +960,7 @@
     /* Try the DNS subjectAltNames. */
     match_found = 0;
     if ((subj_alt_names =
-		(STACK*)X509_get_ext_d2i(x509cert, NID_subject_alt_name, NULL, NULL)))
+		(STACK_OF(GENERAL_NAME) *)X509_get_ext_d2i(x509cert, NID_subject_alt_name, NULL, NULL)))
     {
 	subj_alt_names_count = sk_GENERAL_NAME_num(subj_alt_names);
 	for (i = 0; i < subj_alt_names_count; i++) 
@@ -1105,7 +1105,11 @@
 
 #ifdef HAVE_OPENSSL
     
+    #if OPENSSL_VERSION_NUMBER >= 0x10000000L
+    const SSL_METHOD *ssl_method = NULL;
+    #else
     SSL_METHOD *ssl_method = NULL;
+    #endif
     
     ssl_method = force_sslv3 ? SSLv3_client_method() : SSLv23_client_method();
     if (!ssl_method)
