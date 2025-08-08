--- src/external/pac_responder.m4.orig
+++ src/external/pac_responder.m4
@@ -23,7 +23,8 @@ then
         Kerberos\ 5\ release\ 1.18* | \
         Kerberos\ 5\ release\ 1.19* | \
         Kerberos\ 5\ release\ 1.20* | \
-        Kerberos\ 5\ release\ 1.21*)
+        Kerberos\ 5\ release\ 1.21* | \
+        Kerberos\ 5\ release\ 1.22*)
             krb5_version_ok=yes
             AC_MSG_RESULT([yes])
             ;;
