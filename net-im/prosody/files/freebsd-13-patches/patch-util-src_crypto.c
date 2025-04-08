--- util-src/crypto.c.orig	2025-03-13 13:12:42 UTC
+++ util-src/crypto.c
@@ -27,7 +27,6 @@ typedef unsigned __int32 uint32_t;
 #include <openssl/err.h>
 #include <openssl/evp.h>
 #include <openssl/obj_mac.h>
-#include <openssl/param_build.h>
 #include <openssl/pem.h>
 
 #if (LUA_VERSION_NUM == 501)
@@ -93,40 +92,6 @@ static int Lpkey_meth_get_type(lua_State *L) {
 	return 1;
 }
 
-static int Lpkey_meth_derive(lua_State *L) {
-	size_t outlen;
-	EVP_PKEY *key = pkey_from_arg(L, 1, 0, 0);
-	EVP_PKEY *peer = pkey_from_arg(L, 2, 0, 0);
-	EVP_PKEY_CTX *ctx;
-	BUF_MEM *buf;
-	BIO *bio = new_managed_BIO_s_mem(L);
-	BIO_get_mem_ptr(bio, &buf);
-	if (!(ctx = EVP_PKEY_CTX_new(key, NULL)))
-		goto sslerr;
-	if (EVP_PKEY_derive_init(ctx) <= 0)
-		goto sslerr;
-	if (EVP_PKEY_derive_set_peer(ctx, peer) <= 0)
-		goto sslerr;
-	if (EVP_PKEY_derive(ctx, NULL, &outlen) <= 0)
-		goto sslerr;
-	if (!BUF_MEM_grow_clean(buf, outlen))
-		goto sslerr;
-	if (EVP_PKEY_derive(ctx, (unsigned char*)buf->data, &outlen) <= 0)
-		goto sslerr;
-	EVP_PKEY_CTX_free(ctx);
-	ctx = NULL;
-	lua_pushlstring(L, buf->data, outlen);
-	BIO_reset(bio);
-	return 1;
-sslerr:
-	if (ctx) {
-		EVP_PKEY_CTX_free(ctx);
-		ctx = NULL;
-	}
-	BIO_reset(bio);
-	return luaL_error(L, "pkey:derive failed");
-}
-
 static int base_evp_sign(lua_State *L, const int key_type, const EVP_MD *digest_type) {
 	EVP_PKEY *pkey = pkey_from_arg(L, 1, (key_type!=NID_rsassaPss)?key_type:NID_rsaEncryption, 1);
 	luaL_Buffer sigbuf;
@@ -198,28 +163,6 @@ cleanup:
 	return 1;
 }
 
-static int Lpkey_meth_public_raw(lua_State *L) {
-	OSSL_PARAM *params;
-	EVP_PKEY *pkey = pkey_from_arg(L, 1, 0, 0);
-
-	if (EVP_PKEY_todata(pkey, EVP_PKEY_PUBLIC_KEY, &params)) {
-		OSSL_PARAM *item = params;
-		while (item->key) {
-			if (!strcmp("pub", item->key)) {
-				lua_pushlstring(L, item->data, item->data_size);
-				break;
-			}
-			item++;
-		}
-		if (!item->key) lua_pushnil(L);
-		OSSL_PARAM_free(params);
-	} else {
-		lua_pushnil(L);
-	}
-
-	return 1;
-}
-
 static int Lpkey_meth_public_pem(lua_State *L) {
 	char *data;
 	size_t bytes;
@@ -294,25 +237,6 @@ static int Lgenerate_ed25519_keypair(lua_State *L) {
 	return 1;
 }
 
-static int Lgenerate_p256_keypair(lua_State *L) {
-	EVP_PKEY *pkey = NULL;
-	EVP_PKEY_CTX *pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL);
-
-	/* Generate key */
-	if (EVP_PKEY_keygen_init(pctx) <= 0) goto err;
-	if (EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pctx, NID_X9_62_prime256v1) <= 0) goto err;
-	if (EVP_PKEY_keygen(pctx, &pkey) <= 0) goto err;
-	EVP_PKEY_CTX_free(pctx);
-
-	push_pkey(L, pkey, NID_X9_62_prime256v1, 1);
-	return 1;
-
-err:
-	if (pctx) EVP_PKEY_CTX_free(pctx);
-	lua_pushnil(L);
-	return 1;
-}
-
 static int Limport_private_pem(lua_State *L) {
 	EVP_PKEY *pkey = NULL;
 
@@ -333,42 +257,6 @@ static int Limport_private_pem(lua_State *L) {
 	return 1;
 }
 
-static int Limport_public_ec_raw(lua_State *L) {
-	OSSL_PARAM_BLD *param_bld = NULL;
-	OSSL_PARAM *params = NULL;
-	EVP_PKEY_CTX *ctx = NULL;
-	EVP_PKEY *pkey = NULL;
-
-	size_t pubkey_bytes;
-	const char* pubkey_data = luaL_checklstring(L, 1, &pubkey_bytes);
-	const char* curve = luaL_checkstring(L, 2);
-
-	param_bld = OSSL_PARAM_BLD_new();
-	if (!param_bld) goto err;
-	if (!OSSL_PARAM_BLD_push_utf8_string(param_bld, "group", curve, 0)) goto err;
-	if (!OSSL_PARAM_BLD_push_octet_string(param_bld, "pub", pubkey_data, pubkey_bytes)) goto err;
-	params = OSSL_PARAM_BLD_to_param(param_bld);
-	if (!params) goto err;
-	ctx = EVP_PKEY_CTX_new_from_name(NULL, "EC", NULL);
-	if (!ctx) goto err;
-	if (!EVP_PKEY_fromdata_init(ctx)) goto err;
-	if (EVP_PKEY_fromdata(ctx, &pkey, EVP_PKEY_PUBLIC_KEY, params) <= 0) goto err;
-
-	push_pkey(L, pkey, EVP_PKEY_id(pkey), 0);
-
-	EVP_PKEY_CTX_free(ctx);
-	OSSL_PARAM_free(params);
-	OSSL_PARAM_BLD_free(param_bld);
-
-	return 1;
-err:
-	if (ctx) EVP_PKEY_CTX_free(ctx);
-	if (params) OSSL_PARAM_free(params);
-	if (param_bld) OSSL_PARAM_BLD_free(param_bld);
-	lua_pushnil(L);
-	return 1;
-}
-
 static int Limport_public_pem(lua_State *L) {
 	EVP_PKEY *pkey = NULL;
 
@@ -683,11 +571,9 @@ static const luaL_Reg Reg[] = {
 	{ "aes_256_ctr_decrypt",         Laes_256_ctr_decrypt      },
 
 	{ "generate_ed25519_keypair",    Lgenerate_ed25519_keypair },
-	{ "generate_p256_keypair",       Lgenerate_p256_keypair    },
 
 	{ "import_private_pem",          Limport_private_pem       },
 	{ "import_public_pem",           Limport_public_pem        },
-	{ "import_public_ec_raw",        Limport_public_ec_raw     },
 
 	{ "parse_ecdsa_signature",       Lparse_ecdsa_signature    },
 	{ "build_ecdsa_signature",       Lbuild_ecdsa_signature    },
@@ -697,9 +583,7 @@ static const luaL_Reg KeyMethods[] = {
 static const luaL_Reg KeyMethods[] = {
 	{ "private_pem",            Lpkey_meth_private_pem       },
 	{ "public_pem",             Lpkey_meth_public_pem        },
-	{ "public_raw",             Lpkey_meth_public_raw        },
 	{ "get_type",               Lpkey_meth_get_type          },
-	{ "derive",                 Lpkey_meth_derive            },
 	{ NULL,                     NULL                         }
 };
 
