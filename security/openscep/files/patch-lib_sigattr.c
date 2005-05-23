--- lib/sigattr.c.orig	Wed Feb 20 02:40:06 2002
+++ lib/sigattr.c	Thu May 19 16:26:46 2005
@@ -8,6 +8,7 @@
 #include <sigattr.h>
 #include <init.h>
 #include <openssl/err.h>
+#include <openssl/opensslv.h>
 
 /*
  * read an attribute of type string
@@ -120,6 +121,7 @@
 	X509_ATTRIBUTE			*attr;
 	int				i;
 	scepmsg_t			*msg;
+	int single;
 	
 	if (debug)
 		BIO_printf(bio_err, "%s:%d: looking for attribute '%s'\n",
@@ -146,8 +148,14 @@
 	for (i = 0; i < sk_X509_ATTRIBUTE_num(sig_attribs); i++) {
 		attr = sk_X509_ATTRIBUTE_value(sig_attribs, i);
 		if (OBJ_cmp(attr->object, asn1_obj) == 0) {
-			if ((!attr->set) || (sk_ASN1_TYPE_num(attr->value.set)
-				== 0)) {
+#if OPENSSL_VERSION_NUMBER < 0x00907000L
+			/* attr->set was replaced with attr->single (with opposite
+			   meaning) somewhere between 0.9.6m-engine and 0.9.7d */
+			single = !attr->set;
+#else
+			single = attr->single;
+#endif
+			if (single || (sk_ASN1_TYPE_num(attr->value.set) == 0)) {
 				BIO_printf(bio_err, "%s:%d: attr has no val\n",
 					__FILE__, __LINE__);
 				goto err;
