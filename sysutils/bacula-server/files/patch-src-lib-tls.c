--- src/lib/tls.c.orig	2010-05-20 20:34:49.000000000 +0300
+++ src/lib/tls.c	2010-05-20 20:35:19.000000000 +0300
@@ -315,7 +315,7 @@
          extname = OBJ_nid2sn(OBJ_obj2nid(X509_EXTENSION_get_object(ext)));
 
          if (strcmp(extname, "subjectAltName") == 0) {
-#ifdef HAVE_OPENSSLv1
+#if (OPENSSL_VERSION_NUMBER >= 0x10000000L)
             const X509V3_EXT_METHOD *method;
 #else
             X509V3_EXT_METHOD *method;
