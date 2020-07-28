--- crypto.cpp.orig	2016-11-11 20:23:00 UTC
+++ crypto.cpp
@@ -155,9 +155,13 @@ std::unique_ptr<key> decrypt_header( file_t fromfd, RS
     unsigned char *buff=filemap.get_uc()+sizeof(HEADER_ENCRYPTION_VERSION);
     auto_array<unsigned char> decrypted(new unsigned char[headsize]);
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+    if( (prv->p==nullptr || prv->q==nullptr) ) {
+#else
     const BIGNUM *p, *q;
     RSA_get0_factors(prv, &p, &q);
     if( (p==nullptr || q==nullptr) ) {
+#endif
         // This is not a private key!
         throw rscerror("Neither AES session key nor RSA private key present - cannot decrypt using only public key");
     }
