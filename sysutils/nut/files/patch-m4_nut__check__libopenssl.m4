--- m4/nut_check_libopenssl.m4.orig	2015-12-29 00:42:34.000000000 -0800
+++ m4/nut_check_libopenssl.m4	2018-10-23 12:32:09.902960000 -0700
@@ -58,7 +58,6 @@
 
 	dnl check if openssl is usable
 	AC_CHECK_HEADERS(openssl/ssl.h, [nut_have_openssl=yes], [nut_have_openssl=no], [AC_INCLUDES_DEFAULT])
-	AC_CHECK_FUNCS(SSL_library_init, [], [nut_have_openssl=no])
 
 	if test "${nut_have_openssl}" = "yes"; then
 		nut_with_ssl="yes"
