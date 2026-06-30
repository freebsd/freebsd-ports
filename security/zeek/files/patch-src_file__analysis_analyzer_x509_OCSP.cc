--- src/file_analysis/analyzer/x509/OCSP.cc.orig	2026-05-12 18:14:44 UTC
+++ src/file_analysis/analyzer/x509/OCSP.cc
@@ -26,7 +26,8 @@ static bool OCSP_RESPID_bio(OCSP_BASICRESP* basic_resp
 static constexpr size_t OCSP_STRING_BUF_SIZE = 2048;
 
 static bool OCSP_RESPID_bio(OCSP_BASICRESP* basic_resp, BIO* bio) {
-#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) || defined(LIBRESSL_VERSION_NUMBER)
+#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) ||                                                                        \
+    (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x30900000L))
     ASN1_OCTET_STRING* key = nullptr;
     X509_NAME* name = nullptr;
 
@@ -353,7 +354,8 @@ void OCSP::ParseRequest(OCSP_REQUEST* req) {
 
     uint64_t version = 0;
 
-#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) || defined(LIBRESSL_VERSION_NUMBER)
+#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) ||                                                                        \
+    (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x30900000L))
     if ( req->tbsRequest->version )
         version = (uint64_t)ASN1_INTEGER_get(req->tbsRequest->version);
 #else
@@ -425,7 +427,8 @@ void OCSP::ParseResponse(OCSP_RESPONSE* resp) {
     if ( ! basic_resp )
         goto clean_up;
 
-#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) || defined(LIBRESSL_VERSION_NUMBER)
+#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) ||                                                                        \
+    (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x30900000L))
     resp_data = basic_resp->tbsResponseData;
     if ( ! resp_data )
         goto clean_up;
@@ -434,7 +437,8 @@ void OCSP::ParseResponse(OCSP_RESPONSE* resp) {
     vl.emplace_back(GetFile()->ToVal());
     vl.emplace_back(std::move(status_val));
 
-#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) || defined(LIBRESSL_VERSION_NUMBER)
+#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) ||                                                                        \
+    (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x30900000L))
     vl.emplace_back(val_mgr->Count((uint64_t)ASN1_INTEGER_get(resp_data->version)));
 #else
     vl.emplace_back(parse_basic_resp_data_version(basic_resp));
@@ -451,8 +455,9 @@ void OCSP::ParseResponse(OCSP_RESPONSE* resp) {
         vl.emplace_back(val_mgr->EmptyString());
     }
 
-    // producedAt
-#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) || defined(LIBRESSL_VERSION_NUMBER)
+// producedAt
+#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) ||                                                                        \
+    (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x30900000L))
     produced_at = resp_data->producedAt;
 #else
     produced_at = OCSP_resp_get0_produced_at(basic_resp);
@@ -477,7 +482,8 @@ void OCSP::ParseResponse(OCSP_RESPONSE* resp) {
         // cert id
         const OCSP_CERTID* cert_id = nullptr;
 
-#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) || defined(LIBRESSL_VERSION_NUMBER)
+#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) ||                                                                        \
+    (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x30900000L))
         cert_id = single_resp->certId;
 #else
         cert_id = OCSP_SINGLERESP_get0_id(single_resp);
@@ -550,7 +556,8 @@ void OCSP::ParseResponse(OCSP_RESPONSE* resp) {
         }
     }
 
-#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) || defined(LIBRESSL_VERSION_NUMBER)
+#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) ||                                                                        \
+    (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x30900000L))
     i2a_ASN1_OBJECT(bio, basic_resp->signatureAlgorithm->algorithm);
     len = BIO_read(bio, buf, sizeof(buf));
     vl.emplace_back(make_intrusive<StringVal>(len, buf));
@@ -567,7 +574,8 @@ void OCSP::ParseResponse(OCSP_RESPONSE* resp) {
     certs_vector = new VectorVal(id::find_type<VectorType>("x509_opaque_vector"));
     vl.emplace_back(AdoptRef{}, certs_vector);
 
-#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) || defined(LIBRESSL_VERSION_NUMBER)
+#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) ||                                                                        \
+    (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x30900000L))
     certs = basic_resp->certs;
 #else
     certs = OCSP_resp_get0_certs(basic_resp);
