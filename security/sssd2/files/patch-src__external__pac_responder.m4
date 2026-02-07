--- src/external/pac_responder.m4.orig	2025-08-08 04:17:31.487369000 +0200
+++ src/external/pac_responder.m4	2025-08-08 04:17:52.437575000 +0200
@@ -23,7 +23,8 @@
         Kerberos\ 5\ release\ 1.18* | \
         Kerberos\ 5\ release\ 1.19* | \
         Kerberos\ 5\ release\ 1.20* | \
-        Kerberos\ 5\ release\ 1.21*)
+        Kerberos\ 5\ release\ 1.21* | \
+        Kerberos\ 5\ release\ 1.22*)
             krb5_version_ok=yes
             AC_MSG_RESULT([yes])
             ;;
