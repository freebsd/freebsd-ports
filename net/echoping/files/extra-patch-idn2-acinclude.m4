--- acinclude.m4.orig	2019-12-29 17:14:41.000000000 +0700
+++ acinclude.m4	2025-05-05 00:12:04.181029000 +0700
@@ -166,6 +166,13 @@
 [AC_ERROR([Get the GNU libidn library (http://www.josefsson.org/libidn/) in order to use Unicode - multi-script - domain names or use --without-libidn to disable it])], dnl
 )])
 
+AC_DEFUN([CF_LIB_LIBIDN2],
+[
+AC_CHECK_LIB(idn2,idn2_to_ascii_8z,
+[LIBS="${LIBS} -lidn2"],
+[AC_ERROR([Get the GNU libidn2 library (https://www.gnu.org/software/libidn/) in order to use Unicode - multi-script - domain names or use --without-libidn2 to disable it])], dnl
+)])
+
 # Check OpenSSL
 AC_DEFUN([CF_LIB_OPENSSL],
 [
