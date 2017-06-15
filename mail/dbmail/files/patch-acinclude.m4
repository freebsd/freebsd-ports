--- acinclude.m4.orig	2015-01-25 10:20:50 UTC
+++ acinclude.m4
@@ -221,7 +221,7 @@ if ( test [ "x$lookforldap" != "xno" ] |
         dnl See if we already have the paths we need in the environment.
 	dnl ...but only if --with-ldap was given without a specific path.
         if ( test [ "x$lookforldap" = "xyes" ] || test [ "x$lookforauthldap" = "xyes" ] ); then
-            AC_CHECK_HEADERS([ldap.h],[LDAPLIB="-lldap"], [LDAPLIB="failed"])
+            AC_CHECK_HEADERS([ldap.h],[LDAPLIB="-lldap_r"], [LDAPLIB="failed"])
             if test [ "x$LDAPLIB" != "xfailed" ]; then
                 break
             fi
@@ -233,7 +233,7 @@ if ( test [ "x$lookforldap" != "xno" ] |
             SAVE_CFLAGS=$CFLAGS
 	    dnl The headers might be in a funny place, so we need to use -Ipath
             CFLAGS="$CFLAGS -L$TEST_PATH $LDAPINC"
-            AC_CHECK_HEADERS([ldap.h],[LDAPLIB="-L$TEST_PATH -lldap"], [LDAPLIB="failed"])
+            AC_CHECK_HEADERS([ldap.h],[LDAPLIB="-L$TEST_PATH -lldap_r"], [LDAPLIB="failed"])
             CFLAGS=$SAVE_CFLAGS
             if test [ "x$LDAPLIB" != "xfailed" ]; then
                 break 2
@@ -247,7 +247,7 @@ if ( test [ "x$lookforldap" != "xno" ] |
         AC_MSG_ERROR([Could not find LDAP library.])
     else
         AC_DEFINE([AUTHLDAP], 1, [Define if LDAP will be used.])
-        AC_SEARCH_LIBS(ldap_initialize, ldap, AC_DEFINE([HAVE_LDAP_INITIALIZE], 1, [ldap_initialize() can be used instead of ldap_init()]))
+        AC_SEARCH_LIBS(ldap_initialize, ldap_r, AC_DEFINE([HAVE_LDAP_INITIALIZE], 1, [ldap_initialize() can be used instead of ldap_init()]))
         AC_SUBST(LDAPLIB)
         AC_SUBST(LDAPINC)
         AUTHALIB="modules/.libs/libauth_ldap.a"
