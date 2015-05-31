--- acinclude.m4.orig	2012-07-06 15:23:21 UTC
+++ acinclude.m4
@@ -455,6 +455,9 @@ if test "x$ap_ssltk_configured" = "x"; t
     AC_CHECK_HEADERS([openssl/engine.h])
     AC_CHECK_FUNCS([SSLeay_version SSL_CTX_new], [], [liberrors="yes"])
     AC_CHECK_FUNCS([ENGINE_init ENGINE_load_builtin_engines])
+    dnl PR 196256, https://issues.apache.org/bugzilla/show_bug.cgi?id=57395
+    AC_CHECK_FUNCS([SSL_CTX_use_certificate_chain])
+    AC_CHECK_LIB(crypto, RAND_egd, AC_DEFINE(HAVE_SSL_RAND_EGD, 1, [Define if the libcrypto has RAND_egd]))
   else
     AC_CHECK_FUNCS([SSLC_library_version SSL_CTX_new], [], [liberrors="yes"])
     AC_CHECK_FUNCS(SSL_set_state)
