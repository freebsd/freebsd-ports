--- tls.c.orig	Tue Dec 14 16:23:14 2004
+++ tls.c	Thu Jan 20 11:35:58 2005
@@ -194,6 +194,7 @@
     char            *line;
     int             ntype;
     struct in_addr  addr;
+    int             alt_ext;
 
     if ( inet_aton( host, &addr )) {
 	ntype = IS_IP4;
@@ -239,7 +240,7 @@
     /* This code gratiously borrowed from openldap-2.2.17,
      * it allows the use of aliases in the certificate.
      */
-    int alt_ext = X509_get_ext_by_NID( peer, NID_subject_alt_name, -1);
+    alt_ext = X509_get_ext_by_NID( peer, NID_subject_alt_name, -1);
 
     if ( alt_ext >= 0 ) {
 	X509_EXTENSION			*ex;
