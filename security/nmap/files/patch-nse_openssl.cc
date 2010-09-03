--- ./nse_openssl.cc.orig	2010-03-28 23:18:02.000000000 +0200
+++ ./nse_openssl.cc	2010-08-29 21:25:18.000000000 +0200
@@ -8,7 +8,6 @@
 #include <openssl/crypto.h>
 #include <openssl/bn.h>
 #include <openssl/rand.h>
-#include <openssl/md2.h>
 #include <openssl/md4.h>
 #include <openssl/md5.h>
 #include <openssl/sha.h>
@@ -219,16 +218,6 @@
   return 1;
 }
 
-static int l_md2(lua_State *L)     /** md2(string s) */
-{
-  size_t len;
-  const unsigned char *s = (unsigned char *) luaL_checklstring( L, 1, &len );
-  unsigned char digest[16];
- 
-  lua_pushlstring( L, (char *) MD2( s, len, digest ), 16 );
-  return 1;
-}
-
 static int l_md4(lua_State *L)     /** md4(string s) */
 {
   size_t len;
@@ -515,7 +504,6 @@
   { "bignum_mod_exp", l_bignum_mod_exp },
   { "rand_bytes", l_rand_bytes },
   { "rand_pseudo_bytes", l_rand_pseudo_bytes },
-  { "md2", l_md2 },
   { "md4", l_md4 },
   { "md5", l_md5 },
   { "sha1", l_sha1 },
