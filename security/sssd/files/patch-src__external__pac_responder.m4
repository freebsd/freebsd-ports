diff --git src/external/pac_responder.m4 src/external/pac_responder.m4
index 6e29452..50bf4a8 100644
--- src/external/pac_responder.m4
+++ src/external/pac_responder.m4
@@ -14,14 +14,15 @@ then
     PKG_CHECK_MODULES(NDR_KRB5PAC, ndr_krb5pac, ndr_krb5pac_ok=yes,
         AC_MSG_WARN([Cannot build pac responder without libndr_krb5pac]))
 
-    AC_PATH_PROG(KRB5_CONFIG, krb5-config)
+    AC_PATH_PROG(KRB5_CONFIG, krb5-config, [], [/usr/local/bin:$PATH])
     AC_MSG_CHECKING(for supported MIT krb5 version)
     KRB5_VERSION="`$KRB5_CONFIG --version`"
     case $KRB5_VERSION in
         Kerberos\ 5\ release\ 1.9* | \
         Kerberos\ 5\ release\ 1.10* | \
         Kerberos\ 5\ release\ 1.11* | \
-        Kerberos\ 5\ release\ 1.12*)
+        Kerberos\ 5\ release\ 1.12* | \
+        Kerberos\ 5\ release\ 1.13*)
             krb5_version_ok=yes
             AC_MSG_RESULT([yes])
             ;;
