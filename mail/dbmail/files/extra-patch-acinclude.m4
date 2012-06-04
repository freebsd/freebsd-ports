--- acinclude.m4.orig	2012-05-30 16:42:44.000000000 +0100
+++ acinclude.m4	2012-05-30 16:44:28.000000000 +0100
@@ -235,7 +235,7 @@
         dnl See if we already have the paths we need in the environment.
 	dnl ...but only if --with-ldap was given without a specific path.
         if ( test [ "x$lookforldap" = "xyes" ] || test [ "x$lookforauthldap" = "xyes" ] ); then
-            AC_CHECK_HEADERS([ldap.h],[LDAPLIB="-lldap"], [LDAPLIB="failed"])
+            AC_CHECK_HEADERS([ldap.h],[LDAPLIB="-lldap_r"], [LDAPLIB="failed"])
             if test [ "x$LDAPLIB" != "xfailed" ]; then
                 break
             fi
@@ -247,7 +247,7 @@
             SAVE_CFLAGS=$CFLAGS
 	    dnl The headers might be in a funny place, so we need to use -Ipath
             CFLAGS="$CFLAGS -L$TEST_PATH $LDAPINC"
-            AC_CHECK_HEADERS([ldap.h],[LDAPLIB="-L$TEST_PATH -lldap"], [LDAPLIB="failed"])
+            AC_CHECK_HEADERS([ldap.h],[LDAPLIB="-L$TEST_PATH -lldap_r"], [LDAPLIB="failed"])
             CFLAGS=$SAVE_CFLAGS
             if test [ "x$LDAPLIB" != "xfailed" ]; then
                 break 2
