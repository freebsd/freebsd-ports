--- src/lua_crypto.c.orig	2019-01-12 14:43:35 UTC
+++ src/lua_crypto.c
@@ -124,7 +124,7 @@ static EVP_MD_CTX *evp_pget(lua_State *L, int i) {
 }
 
 static EVP_MD_CTX *evp_pnew(lua_State *L) {
-  EVP_MD_CTX *c = lua_newuserdata(L, sizeof(EVP_MD_CTX));
+  EVP_MD_CTX *c = lua_newuserdata(L, sizeof(c));
   luaL_getmetatable(L, LUACRYPTO_EVP);
   lua_setmetatable(L, -2);
   return c;
@@ -158,8 +158,7 @@ static int evp_clone(lua_State *L) {
 static int evp_reset(lua_State *L) {
   EVP_MD_CTX *c = evp_pget(L, 1);
   const EVP_MD *t = EVP_MD_CTX_md(c);
-  EVP_MD_CTX_cleanup(c);
-  EVP_MD_CTX_init(c);
+  EVP_MD_CTX_reset(c);
   EVP_DigestInit_ex(c, t, NULL);
   return 0;
 }
@@ -216,7 +215,7 @@ static int evp_tostring(lua_State *L) {
 
 static int evp_gc(lua_State *L) {
   EVP_MD_CTX *c = evp_pget(L, 1);
-  EVP_MD_CTX_cleanup(c);
+  EVP_MD_CTX_free(c);
   return 1;
 }
 
@@ -266,7 +265,7 @@ static HMAC_CTX *hmac_pget(lua_State *L, int i) {
 }
 
 static HMAC_CTX *hmac_pnew(lua_State *L) {
-  HMAC_CTX *c = lua_newuserdata(L, sizeof(HMAC_CTX));
+  HMAC_CTX *c = lua_newuserdata(L, sizeof(c));
   luaL_getmetatable(L, LUACRYPTO_HMAC);
   lua_setmetatable(L, -2);
   return c;
@@ -283,7 +282,7 @@ static int hmac_fnew(lua_State *L) {
     return 0;
   }
 
-  HMAC_CTX_init(c);
+  c = HMAC_CTX_new();
   HMAC_Init_ex(c, k, strlen(k), type, NULL);
 
   return 1;
@@ -292,7 +291,7 @@ static int hmac_fnew(lua_State *L) {
 static int hmac_clone(lua_State *L) {
  HMAC_CTX *c = hmac_pget(L, 1);
  HMAC_CTX *d = hmac_pnew(L);
- *d = *c;
+ HMAC_CTX_copy(d, c);
  return 1;
 }
 
@@ -352,12 +351,12 @@ static int hmac_tostring(lua_State *L) {
 
 static int hmac_gc(lua_State *L) {
   HMAC_CTX *c = hmac_pget(L, 1);
-  HMAC_CTX_cleanup(c);
+  HMAC_CTX_free(c);
   return 1;
 }
 
 static int hmac_fdigest(lua_State *L) {
-  HMAC_CTX c;
+  HMAC_CTX *c;
   unsigned char digest[EVP_MAX_MD_SIZE];
   unsigned int written = 0;
   unsigned int i;
@@ -372,10 +371,11 @@ static int hmac_fdigest(lua_State *L) {
     return 0;
   }
 
-  HMAC_CTX_init(&c);
-  HMAC_Init_ex(&c, k, strlen(k), type, NULL);
-  HMAC_Update(&c, (unsigned char *)s, strlen(s));
-  HMAC_Final(&c, digest, &written);
+  c = HMAC_CTX_new();
+  HMAC_Init_ex(c, k, strlen(k), type, NULL);
+  HMAC_Update(c, (unsigned char *)s, strlen(s));
+  HMAC_Final(c, digest, &written);
+  HMAC_CTX_free(c);
 
   if (lua_toboolean(L, 4)) {
     lua_pushlstring(L, (char *)digest, written);
@@ -696,7 +696,7 @@ static ASN1_TIME *asn1_time_pget(lua_State *L, int i) 
 }
 
 static int asn1_time_fnew(lua_State *L) {
-  ASN1_TIME *asn1time = M_ASN1_TIME_new(); 
+  ASN1_TIME *asn1time = (ASN1_TIME *)ASN1_STRING_type_new(V_ASN1_UTCTIME);
   time_t t = time(NULL);
   ASN1_TIME_set(asn1time, t);
   lua_pushlightuserdata(L, asn1time);
@@ -708,7 +708,7 @@ static int asn1_time_fnew(lua_State *L) {
 
 static int asn1_time_clone(lua_State *L) {
   ASN1_TIME *time = asn1_time_pget(L, 1);
-  ASN1_TIME *copy = M_ASN1_TIME_dup(time);
+  ASN1_TIME *copy = ASN1_STRING_dup((const ASN1_STRING *)time);
 
   lua_pushlightuserdata(L, copy);
   luaL_getmetatable(L, LUACRYPTO_ASN1TIME);
@@ -738,7 +738,7 @@ static int asn1_time_toasn1(lua_State *L) {
 
 static int asn1_time_gc(lua_State *L) {
   ASN1_TIME *time = asn1_time_pget(L, 1);
-  M_ASN1_TIME_free(time);
+  ASN1_STRING_free((ASN1_STRING *)time);
   return 1;
 }
 
@@ -763,8 +763,8 @@ static int dh_cb(int p, int n, BN_GENCB *cb) {
     c='\n';
     break;
   }
-  BIO_write(cb->arg,&c,1);
-  (void)BIO_flush(cb->arg);
+  BIO_write(BN_GENCB_get_arg(cb),&c,1);
+  (void)BIO_flush(BN_GENCB_get_arg(cb));
   return 1;
 }
 
@@ -780,19 +780,26 @@ static int dh_fnew(lua_State *L) {
   int num = luaL_checknumber(L, 2);
   DH *dh = DH_new();
   BIO *bio_err;
-  BN_GENCB cb;
+  BN_GENCB *cb;
+  cb = BN_GENCB_new();
+  if (!cb) {
+    luaL_argerror(L, 1, "could not create BN_GENCB structure");
+    return 1;
+  }
   if ((bio_err = BIO_new(BIO_s_file())) != NULL) {
     BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
   }
-  BN_GENCB_set(&cb, dh_cb, bio_err);
-  if (!DH_generate_parameters_ex(dh, num, generator, &cb)) {
+  BN_GENCB_set(cb, dh_cb, bio_err);
+  if (!DH_generate_parameters_ex(dh, num, generator, cb)) {
     luaL_argerror(L, 1, "could not generate DH paramters");
+    BN_GENCB_free(cb);
     return 1;
   }
   DH_generate_key(dh);
   lua_pushlightuserdata(L, dh);
   luaL_getmetatable(L, LUACRYPTO_DH);
   lua_setmetatable(L, -2);
+  BN_GENCB_free(cb);
 
   return 1;
 }
@@ -824,8 +831,8 @@ static int dh_get_prime(lua_State *L) {
   apr_pool_t *pool;
   DH *dh = dh_pget(L, 1);
   HT_POOL_CREATE(&pool);
-  s = apr_pcalloc(pool, BN_num_bytes(dh->p)); 
-  len = BN_bn2bin(dh->p, s);
+  s = apr_pcalloc(pool, BN_num_bytes(DH_get0_p(dh))); 
+  len = BN_bn2bin(DH_get0_p(dh), s);
   lua_pushlstring(L, (char *)s, len);
   apr_pool_destroy(pool);
   return 1;
@@ -837,8 +844,8 @@ static int dh_get_priv_key(lua_State *L) {
   apr_pool_t *pool;
   DH *dh = dh_pget(L, 1);
   HT_POOL_CREATE(&pool);
-  s = apr_pcalloc(pool, BN_num_bytes(dh->priv_key)); 
-  len = BN_bn2bin(dh->priv_key, s);
+  s = apr_pcalloc(pool, BN_num_bytes(DH_get0_priv_key(dh))); 
+  len = BN_bn2bin(DH_get0_priv_key(dh), s);
   lua_pushlstring(L, (char *)s, len);
   apr_pool_destroy(pool);
   return 1;
@@ -850,8 +857,8 @@ static int dh_get_pub_key(lua_State *L) {
   apr_pool_t *pool;
   DH *dh = dh_pget(L, 1);
   HT_POOL_CREATE(&pool);
-  s = apr_pcalloc(pool, BN_num_bytes(dh->pub_key)); 
-  len = BN_bn2bin(dh->pub_key, s);
+  s = apr_pcalloc(pool, BN_num_bytes(DH_get0_pub_key(dh))); 
+  len = BN_bn2bin(DH_get0_pub_key(dh), s);
   lua_pushlstring(L, (char *)s, len);
   apr_pool_destroy(pool);
   return 1;
