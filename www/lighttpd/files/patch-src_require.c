--- src/response.c.orig	2009-11-30 13:49:22.000000000 -0200
+++ src/response.c	2009-11-30 13:52:28.000000000 -0200
@@ -136,6 +136,7 @@
 	X509 *xs;
 	X509_NAME *xn;
 	X509_NAME_ENTRY *xe;
+	int i, nentries;
 	if (
 		SSL_get_verify_result(con->ssl) != X509_V_OK
 		|| !(xs = SSL_get_peer_certificate(con->ssl))
@@ -144,7 +145,8 @@
 	}
 
 	xn = X509_get_subject_name(xs);
-	for (int i = 0, nentries = X509_NAME_entry_count(xn); i < nentries; ++i) {
+	nentries = X509_NAME_entry_count(xn);
+	for (i = 0; i < nentries; ++i) {
 		int xobjnid;
 		const char * xobjsn;
 		data_string *envds;
