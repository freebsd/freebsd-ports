--- src/external/krb5.m4.orig	2020-03-17 13:31:28 UTC
+++ src/external/krb5.m4
@@ -9,7 +9,7 @@ fi
     KRB5_PASSED_CFLAGS=$KRB5_CFLAGS
 fi
 
-AC_PATH_TOOL(KRB5_CONFIG, krb5-config)
+AC_PATH_TOOL(KRB5_CONFIG, krb5-config, [], [/usr/local/bin:$PATH])
 AC_MSG_CHECKING(for working krb5-config)
 if test -x "$KRB5_CONFIG"; then
   KRB5_CFLAGS="`$KRB5_CONFIG --cflags`"
