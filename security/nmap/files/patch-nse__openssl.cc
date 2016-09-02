--- nse_openssl.cc.orig	2016-08-01 09:34:56 UTC
+++ nse_openssl.cc
@@ -281,7 +281,7 @@ static int l_digest(lua_State *L)     /*
   const unsigned char *msg = (unsigned char *) luaL_checklstring( L, 2, &msg_len );
   unsigned char digest[EVP_MAX_MD_SIZE];
   const EVP_MD * evp_md;
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   EVP_MD_CTX mdctx;
 #else
   EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
@@ -291,7 +291,7 @@ static int l_digest(lua_State *L)     /*
 
   if (!evp_md) return luaL_error( L, "Unknown digest algorithm: %s", algorithm );
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   EVP_MD_CTX_init(&mdctx);
   if (!(
       EVP_DigestInit_ex( &mdctx, evp_md, NULL ) &&
@@ -394,7 +394,7 @@ static int l_encrypt(lua_State *L) /** e
   if (iv[0] == '\0')
     iv = NULL;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   EVP_CIPHER_CTX cipher_ctx;
   EVP_CIPHER_CTX_init( &cipher_ctx );
 
@@ -496,7 +496,7 @@ static int l_decrypt(lua_State *L) /** d
   if (iv[0] == '\0')
     iv = NULL;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   EVP_CIPHER_CTX cipher_ctx;
   EVP_CIPHER_CTX_init( &cipher_ctx );
 
@@ -684,7 +684,7 @@ static const struct luaL_Reg openssllib[
 LUALIB_API int luaopen_openssl(lua_State *L) {
 
   OpenSSL_add_all_algorithms();
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   ERR_load_crypto_strings();
 #else
   /* This is now deprecated in OpenSSL 1.1.0 _ No explicit initialisation 
