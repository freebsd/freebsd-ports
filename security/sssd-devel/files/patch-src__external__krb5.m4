--- src/external/krb5.m4.orig	2023-05-05 08:11:07 UTC
+++ src/external/krb5.m4
@@ -1,5 +1,10 @@
+KRB5_CFLAGS="-I/usr/local/include"
+KRB5_LIBS="-L/usr/local/lib -lkrb5"
+KRB5_CONFIG="/usr/local/bin/krb5-config"
+
 AC_SUBST(KRB5_CFLAGS)
 AC_SUBST(KRB5_LIBS)
+AC_SUBST(KRB5_CONFIG)
 
 if test x$KRB5_LIBS != x; then
     KRB5_PASSED_LIBS=$KRB5_LIBS
