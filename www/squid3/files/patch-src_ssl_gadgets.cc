--- src/ssl/gadgets.cc.orig	2018-07-15 20:46:55 UTC
+++ src/ssl/gadgets.cc
@@ -321,7 +321,7 @@ mimicExtensions(Ssl::X509_Pointer & cert, Ssl::X509_Po
                                                 &ext_der,
                                                 (const ASN1_ITEM *)ASN1_ITEM_ptr(method->it));
 
-                    ASN1_OCTET_STRING *ext_oct = M_ASN1_OCTET_STRING_new();
+                    ASN1_OCTET_STRING *ext_oct = ASN1_OCTET_STRING_new();
                     ext_oct->data = ext_der;
                     ext_oct->length = ext_len;
                     X509_EXTENSION_set_data(ext, ext_oct);
