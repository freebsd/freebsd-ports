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
