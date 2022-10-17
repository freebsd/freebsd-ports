--- src/_cffi_src/openssl/x509.py.orig	2022-10-17 11:26:23 UTC
+++ src/_cffi_src/openssl/x509.py
@@ -276,33 +276,8 @@ void X509_REQ_get0_signature(const X509_REQ *, const A
 """
 
 CUSTOMIZATIONS = """
-#if CRYPTOGRAPHY_IS_LIBRESSL
-int i2d_re_X509_tbs(X509 *x, unsigned char **pp)
-{
-    /* in 1.0.2+ this function also sets x->cert_info->enc.modified = 1
-       but older OpenSSLs don't have the enc ASN1_ENCODING member in the
-       X509 struct.  Setting modified to 1 marks the encoding
-       (x->cert_info->enc.enc) as invalid, but since the entire struct isn't
-       present we don't care. */
-    return i2d_X509_CINF(x->cert_info, pp);
-}
-#endif
-
 /* Being kept around for pyOpenSSL */
 X509_REVOKED *Cryptography_X509_REVOKED_dup(X509_REVOKED *rev) {
     return X509_REVOKED_dup(rev);
 }
-/* Added in 1.1.0 but we need it in all versions now due to the great
-   opaquing. */
-#if CRYPTOGRAPHY_IS_LIBRESSL
-int i2d_re_X509_REQ_tbs(X509_REQ *req, unsigned char **pp)
-{
-    req->req_info->enc.modified = 1;
-    return i2d_X509_REQ_INFO(req->req_info, pp);
-}
-int i2d_re_X509_CRL_tbs(X509_CRL *crl, unsigned char **pp) {
-    crl->crl->enc.modified = 1;
-    return i2d_X509_CRL_INFO(crl->crl, pp);
-}
-#endif
 """
