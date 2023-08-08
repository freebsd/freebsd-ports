--- lib/pki_scard.cpp.orig	2021-05-07 20:40:29 UTC
+++ lib/pki_scard.cpp
@@ -293,10 +293,10 @@ pk11_attlist pki_scard::objectAttributesNoId(EVP_PKEY 
 pk11_attlist pki_scard::objectAttributesNoId(EVP_PKEY *pk, bool priv) const
 {
 	QByteArray ba;
-	RSA *rsa;
-	DSA *dsa;
+	const RSA *rsa;
+	const DSA *dsa;
 #ifndef OPENSSL_NO_EC
-	EC_KEY *ec;
+	const EC_KEY *ec;
 #endif
 	const BIGNUM *n = NULL;
 	const BIGNUM *e = NULL;
@@ -401,10 +401,10 @@ void pki_scard::store_token(const slotid &slot, EVP_PK
 void pki_scard::store_token(const slotid &slot, EVP_PKEY *pkey)
 {
 	QByteArray ba;
-	RSA *rsa;
-	DSA *dsa;
+	const RSA *rsa;
+	const DSA *dsa;
 #ifndef OPENSSL_NO_EC
-	EC_KEY *ec;
+	const EC_KEY *ec;
 #endif
 	pk11_attlist pub_atts;
 	pk11_attlist priv_atts;
