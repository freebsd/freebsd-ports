--- acinclude.m4.orig	2012-07-06 17:23:21.000000000 +0200
+++ acinclude.m4	2015-02-28 10:22:26.577650967 +0100
@@ -455,6 +455,8 @@
     AC_CHECK_HEADERS([openssl/engine.h])
     AC_CHECK_FUNCS([SSLeay_version SSL_CTX_new], [], [liberrors="yes"])
     AC_CHECK_FUNCS([ENGINE_init ENGINE_load_builtin_engines])
+    AC_CHECK_FUNCS([SSL_CTX_use_certificate_chain])
+    AC_CHECK_LIB(crypto, RAND_egd, AC_DEFINE(HAVE_SSL_RAND_EGD, 1, [Define if the libcrypto has RAND_egd]))
   else
     AC_CHECK_FUNCS([SSLC_library_version SSL_CTX_new], [], [liberrors="yes"])
     AC_CHECK_FUNCS(SSL_set_state)
