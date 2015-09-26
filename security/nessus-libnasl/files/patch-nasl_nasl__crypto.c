--- nasl/nasl_crypto.c.orig	2015-09-26 16:19:46.667876448 +0200
+++ nasl/nasl_crypto.c	2015-09-26 16:19:12.203879000 +0200
@@ -209,10 +209,12 @@ tree_cell * nasl_hmac_md5(lex_ctxt * lex
  return nasl_hmac(lexic, EVP_md5());
 }
 
+#ifndef OPENSSL_NO_SHA0
 tree_cell * nasl_hmac_sha(lex_ctxt * lexic)
 {
  return nasl_hmac(lexic, EVP_sha());
 }
+#endif
 
 tree_cell * nasl_hmac_sha1(lex_ctxt * lexic)
 {
