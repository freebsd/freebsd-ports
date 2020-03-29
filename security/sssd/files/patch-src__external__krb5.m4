--- src/external/krb5.m4.orig	2014-09-17 13:01:37 UTC
+++ src/external/krb5.m4
@@ -9,7 +9,7 @@ if test x$KRB5_CFLAGS != x; then
     KRB5_PASSED_CFLAGS=$KRB5_CFLAGS
 fi
 
-AC_PATH_PROG(KRB5_CONFIG, krb5-config)
+AC_PATH_PROG(KRB5_CONFIG, krb5-config, [], [/usr/local/bin:$PATH])
 AC_MSG_CHECKING(for working krb5-config)
 if test -x "$KRB5_CONFIG"; then
   KRB5_CFLAGS="`$KRB5_CONFIG --cflags`"
