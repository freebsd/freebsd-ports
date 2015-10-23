--- nasl/nasl_crypto.c.orig	2005-07-07 00:14:26 UTC
+++ nasl/nasl_crypto.c
@@ -22,11 +22,15 @@
   */
 #include <includes.h>
 #ifdef HAVE_SSL
+#ifdef HAVE_OPENSSL_MD2_H
 #include <openssl/md2.h>
+#endif
 #include <openssl/md4.h>
 #include <openssl/md5.h>
 #include <openssl/ripemd.h>
+#ifndef OPENSSL_NO_SHA0
 #include <openssl/sha.h>
+#endif
 #include <openssl/evp.h>
 #include <openssl/hmac.h>
 
@@ -45,6 +49,7 @@
 
 
 /*-------------------[  Std. HASH ]-------------------------------------*/
+#ifdef HAVE_OPENSSL_MD2_H
 tree_cell * nasl_md2(lex_ctxt * lexic)
 {
  char * data = get_str_var_by_num(lexic, 0);
@@ -63,6 +68,7 @@ tree_cell * nasl_md2(lex_ctxt * lexic)
  retc->size = MD2_DIGEST_LENGTH;
  return retc;
 }
+#endif
 
 tree_cell * nasl_md4(lex_ctxt * lexic)
 {
@@ -102,6 +108,7 @@ tree_cell * nasl_md5(lex_ctxt * lexic)
  return retc;
 }
 
+#ifndef OPENSSL_NO_SHA0
 tree_cell * nasl_sha(lex_ctxt * lexic)
 {
  char * data = get_str_var_by_num(lexic, 0);
@@ -120,7 +127,7 @@ tree_cell * nasl_sha(lex_ctxt * lexic)
  retc->size = SHA_DIGEST_LENGTH;
  return retc;
 }
-
+#endif
 
 tree_cell * nasl_sha1(lex_ctxt * lexic)
 {
@@ -192,23 +199,24 @@ static tree_cell * nasl_hmac(lex_ctxt * 
  return retc;
 }
 
-
+#ifdef HAVE_OPENSSL_MD2_H
 tree_cell * nasl_hmac_md2(lex_ctxt * lexic)
 {
  return nasl_hmac(lexic, EVP_md2());
 }
-
+#endif
 
 tree_cell * nasl_hmac_md5(lex_ctxt * lexic)
 {
  return nasl_hmac(lexic, EVP_md5());
 }
 
+#ifndef OPENSSL_NO_SHA0
 tree_cell * nasl_hmac_sha(lex_ctxt * lexic)
 {
  return nasl_hmac(lexic, EVP_sha());
 }
-
+#endif
 
 tree_cell * nasl_hmac_sha1(lex_ctxt * lexic)
 {
