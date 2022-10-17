--- src/_cffi_src/openssl/ocsp.py.orig	2022-10-17 11:14:50 UTC
+++ src/_cffi_src/openssl/ocsp.py
@@ -77,7 +77,6 @@ int i2d_OCSP_RESPDATA(OCSP_RESPDATA *, unsigned char *
 
 CUSTOMIZATIONS = """
 #if ( \
-    !CRYPTOGRAPHY_IS_LIBRESSL && \
     CRYPTOGRAPHY_OPENSSL_LESS_THAN_110J \
     )
 /* These structs come from ocsp_lcl.h and are needed to de-opaque the struct
@@ -104,62 +103,15 @@ struct ocsp_basic_response_st {
 };
 #endif
 
-#if CRYPTOGRAPHY_IS_LIBRESSL
-/* These functions are all taken from ocsp_cl.c in OpenSSL 1.1.0 */
-const OCSP_CERTID *OCSP_SINGLERESP_get0_id(const OCSP_SINGLERESP *single)
-{
-    return single->certId;
-}
-const Cryptography_STACK_OF_X509 *OCSP_resp_get0_certs(
-    const OCSP_BASICRESP *bs)
-{
-    return bs->certs;
-}
-int OCSP_resp_get0_id(const OCSP_BASICRESP *bs,
-                      const ASN1_OCTET_STRING **pid,
-                      const X509_NAME **pname)
-{
-    const OCSP_RESPID *rid = bs->tbsResponseData->responderId;
-
-    if (rid->type == V_OCSP_RESPID_NAME) {
-        *pname = rid->value.byName;
-        *pid = NULL;
-    } else if (rid->type == V_OCSP_RESPID_KEY) {
-        *pid = rid->value.byKey;
-        *pname = NULL;
-    } else {
-        return 0;
-    }
-    return 1;
-}
-const ASN1_GENERALIZEDTIME *OCSP_resp_get0_produced_at(
-    const OCSP_BASICRESP* bs)
-{
-    return bs->tbsResponseData->producedAt;
-}
-const ASN1_OCTET_STRING *OCSP_resp_get0_signature(const OCSP_BASICRESP *bs)
-{
-    return bs->signature;
-}
-#endif
-
 #if CRYPTOGRAPHY_OPENSSL_LESS_THAN_110J
 const X509_ALGOR *OCSP_resp_get0_tbs_sigalg(const OCSP_BASICRESP *bs)
 {
-#if CRYPTOGRAPHY_IS_LIBRESSL
-    return bs->signatureAlgorithm;
-#else
     return &bs->signatureAlgorithm;
-#endif
 }
 
 const OCSP_RESPDATA *OCSP_resp_get0_respdata(const OCSP_BASICRESP *bs)
 {
-#if CRYPTOGRAPHY_IS_LIBRESSL
-    return bs->tbsResponseData;
-#else
     return &bs->tbsResponseData;
-#endif
 }
 #endif
 """
