--- RSA.xs.orig	2017-06-19 18:08:26 UTC
+++ RSA.xs
@@ -179,6 +179,30 @@ RSA* _load_rsa_key(SV* p_keyStringSv,
     return rsa;
 }
 
+
+RSA* _load_enc_rsa_key(SV* p_keyStringSv,
+                   RSA*(*p_loader)(BIO*, RSA**, pem_password_cb*, void*), char* password)
+{
+    STRLEN keyStringLength;
+    char* keyString;
+
+    RSA* rsa;
+    BIO* stringBIO;
+
+    keyString = SvPV(p_keyStringSv, keyStringLength);
+
+    CHECK_OPEN_SSL(stringBIO = BIO_new_mem_buf(keyString, keyStringLength));
+
+    rsa = p_loader(stringBIO, NULL, NULL, password);
+
+    CHECK_OPEN_SSL(BIO_set_close(stringBIO, BIO_CLOSE) == 1);
+    BIO_free(stringBIO);
+
+    CHECK_OPEN_SSL(rsa);
+    return rsa;
+}
+
+
 SV* rsa_crypt(rsaData* p_rsa, SV* p_from,
               int (*p_crypt)(int, const unsigned char*, unsigned char*, RSA*, int))
 {
@@ -214,7 +238,7 @@ BOOT:
     ERR_load_crypto_strings();
 
 SV*
-new_private_key(proto, key_string_SV)
+_new_private_key(proto, key_string_SV)
     SV* proto;
     SV* key_string_SV;
   CODE:
@@ -223,7 +247,24 @@ new_private_key(proto, key_string_SV)
   OUTPUT:
     RETVAL
 
+
 SV*
+_new_enc_private_key(proto, key_string_SV, password_SV)
+    SV* proto;
+    SV* key_string_SV;
+    SV* password_SV;
+  PREINIT:
+    char* password;
+  CODE:
+    password = SvPV_nolen(password_SV);
+
+    RETVAL = make_rsa_obj(
+        proto, _load_enc_rsa_key(key_string_SV, PEM_read_bio_RSAPrivateKey, password));
+  OUTPUT:
+    RETVAL
+
+
+SV*
 _new_public_key_pkcs1(proto, key_string_SV)
     SV* proto;
     SV* key_string_SV;
@@ -251,7 +292,7 @@ DESTROY(p_rsa)
     Safefree(p_rsa);
 
 SV*
-get_private_key_string(p_rsa)
+_get_private_key_string(p_rsa)
     rsaData* p_rsa;
   PREINIT:
     BIO* stringBIO;
@@ -259,6 +300,32 @@ get_private_key_string(p_rsa)
     CHECK_OPEN_SSL(stringBIO = BIO_new(BIO_s_mem()));
     PEM_write_bio_RSAPrivateKey(
         stringBIO, p_rsa->rsa, NULL, NULL, 0, NULL, NULL);
+    RETVAL = extractBioString(stringBIO);
+
+  OUTPUT:
+    RETVAL
+
+
+SV*
+_get_enc_private_key_string(p_rsa, passout_SV, cipher_SV)
+    rsaData* p_rsa;
+    SV* passout_SV;
+    SV* cipher_SV;
+  PREINIT:
+    char* passout;
+    char* cipher;
+
+    BIO* stringBIO;
+    const EVP_CIPHER *enc;
+  CODE:
+    passout = SvPV_nolen(passout_SV);
+    cipher = SvPV_nolen(cipher_SV);
+
+    CHECK_OPEN_SSL(stringBIO = BIO_new(BIO_s_mem()));
+    enc = EVP_get_cipherbyname(cipher);
+    if (enc == NULL) { enc = EVP_get_cipherbyname("DES3"); }
+    PEM_write_bio_RSAPrivateKey(
+        stringBIO, p_rsa->rsa, enc, NULL, 0, NULL, passout);
     RETVAL = extractBioString(stringBIO);
 
   OUTPUT:
