--- plugins/dfxml/src/dfxml_configure.m4.orig	2014-09-16 18:34:02 UTC
+++ plugins/dfxml/src/dfxml_configure.m4
@@ -59,4 +59,5 @@ AC_CHECK_LIB([crypto],[EVP_get_digestbyn
 AC_CHECK_LIB([ssl],[SSL_library_init])
 AC_CHECK_FUNCS([EVP_get_digestbyname],,
 	AC_MSG_ERROR([SSL/OpenSSL support required]))
+AC_CHECK_FUNCS([EVP_MD_CTX_new EVP_MD_CTX_free])
 
