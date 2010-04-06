--- src/modules/ssl/ssl_util_ssl.c.orig	2006-05-08 09:15:38.000000000 +0200
+++ src/modules/ssl/ssl_util_ssl.c	2010-04-06 13:36:01.000000000 +0200
@@ -324,7 +324,7 @@
 {
     X509_EXTENSION *ext;
     int ext_nid;
-    STACK *sk;
+    STACK_OF(SSL_CIPHER) *sk;
     BOOL is_sgc;
     int idx;
     int i;
@@ -333,7 +333,7 @@
     idx = X509_get_ext_by_NID(cert, NID_ext_key_usage, -1);
     if (idx >= 0) {
         ext = X509_get_ext(cert, idx);
-        if ((sk = (STACK *)X509V3_EXT_d2i(ext)) != NULL) {
+        if ((sk = X509V3_EXT_d2i(ext)) != NULL) {
             for (i = 0; i < sk_num(sk); i++) {
                 ext_nid = OBJ_obj2nid((ASN1_OBJECT *)sk_value(sk, i));
                 if (ext_nid == NID_ms_sgc || ext_nid == NID_ns_sgc) {
