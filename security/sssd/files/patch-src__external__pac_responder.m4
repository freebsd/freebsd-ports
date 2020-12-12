diff --git src/external/pac_responder.m4 src/external/pac_responder.m4
index dc986a1b8..09efdb139 100644
--- src/external/pac_responder.m4
+++ src/external/pac_responder.m4
@@ -7,7 +7,7 @@ AC_ARG_ENABLE([pac-responder],
 krb5_version_ok=no
 if test x$build_pac_responder = xyes
 then
-    AC_PATH_PROG(KRB5_CONFIG, krb5-config)
+    AC_PATH_TOOL(KRB5_CONFIG, krb5-config, [], [/usr/local/bin:$PATH])
     AC_MSG_CHECKING(for supported MIT krb5 version)
     KRB5_VERSION="`$KRB5_CONFIG --version`"
     case $KRB5_VERSION in
@@ -19,7 +19,8 @@
         Kerberos\ 5\ release\ 1.14* | \
         Kerberos\ 5\ release\ 1.15* | \
         Kerberos\ 5\ release\ 1.16* | \
-        Kerberos\ 5\ release\ 1.17*)
+        Kerberos\ 5\ release\ 1.17* | \
+        Kerberos\ 5\ release\ 1.18*)
             krb5_version_ok=yes
             AC_MSG_RESULT([yes])
             ;;
