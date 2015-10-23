--- nasl/nasl_crypto.h.orig	2005-02-10 16:03:52 UTC
+++ nasl/nasl_crypto.h
@@ -2,15 +2,23 @@
 #define NASL_CRYPTO_H
 
 #ifdef HAVE_SSL
+#ifdef HAVE_OPENSSL_MD2_H
 tree_cell * nasl_md2(lex_ctxt *);
+#endif
 tree_cell * nasl_md4(lex_ctxt *);
 tree_cell * nasl_md5(lex_ctxt *);
+#ifndef OPENSSL_NO_SHA0
 tree_cell * nasl_sha(lex_ctxt *);
+#endif
 tree_cell * nasl_sha1(lex_ctxt *);
 tree_cell * nasl_ripemd160(lex_ctxt *);
+#ifdef HAVE_OPENSSL_MD2_H
 tree_cell * nasl_hmac_md2(lex_ctxt * );
+#endif
 tree_cell * nasl_hmac_md5(lex_ctxt * );
+#ifndef OPENSSL_NO_SHA0
 tree_cell * nasl_hmac_sha(lex_ctxt *);
+#endif
 tree_cell * nasl_hmac_sha1(lex_ctxt * );
 tree_cell * nasl_hmac_dss(lex_ctxt *);
 tree_cell * nasl_hmac_ripemd160(lex_ctxt *);
