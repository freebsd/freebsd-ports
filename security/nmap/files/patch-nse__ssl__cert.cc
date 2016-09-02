--- nse_ssl_cert.cc.orig	2016-08-30 16:07:08 UTC
+++ nse_ssl_cert.cc
@@ -528,7 +528,7 @@ static int parse_ssl_cert(lua_State *L, 
     lua_setfield(L, -2, "subject");
   }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   const char *sig_algo = OBJ_nid2ln(OBJ_obj2nid(cert->sig_alg->algorithm));
 #else
   const char *sig_algo = OBJ_nid2ln(X509_get_signature_nid(cert));
@@ -555,7 +555,7 @@ static int parse_ssl_cert(lua_State *L, 
     return 2;
   }
   lua_newtable(L);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   pkey_type = EVP_PKEY_type(pubkey->type);
 #else
   pkey_type = EVP_PKEY_base_id(pubkey);
@@ -572,7 +572,7 @@ static int parse_ssl_cert(lua_State *L, 
     bignum_data_t * data = (bignum_data_t *) lua_newuserdata( L, sizeof(bignum_data_t));
     luaL_getmetatable( L, "BIGNUM" );
     lua_setmetatable( L, -2 );
-  #if OPENSSL_VERSION_NUMBER < 0x10100000L
+  #if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     data->bn = rsa->e;
   #elif OPENSSL_VERSION_NUMBER < 0x10100006L
     BIGNUM *n, *e, *d;
