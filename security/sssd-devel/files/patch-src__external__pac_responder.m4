--- src/external/pac_responder.m4.orig	2023-05-05 08:11:07 UTC
+++ src/external/pac_responder.m4
@@ -7,7 +7,7 @@ then
 krb5_version_ok=no
 if test x$build_pac_responder = xyes
 then
-    AC_PATH_PROG(KRB5_CONFIG, krb5-config)
+    AC_PATH_PROG(KRB5_CONFIG, /usr/local/bin/krb5-config)
     AC_MSG_CHECKING(for supported MIT krb5 version)
     KRB5_VERSION="`$KRB5_CONFIG --version`"
     case $KRB5_VERSION in
@@ -22,7 +22,8 @@ then
         Kerberos\ 5\ release\ 1.17* | \
         Kerberos\ 5\ release\ 1.18* | \
         Kerberos\ 5\ release\ 1.19* | \
-        Kerberos\ 5\ release\ 1.20*)
+        Kerberos\ 5\ release\ 1.20* | \
+        Kerberos\ 5\ release\ 1.21*)
             krb5_version_ok=yes
             AC_MSG_RESULT([yes])
             ;;
