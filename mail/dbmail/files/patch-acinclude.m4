--- acinclude.m4.orig	2015-01-25 10:20:50 UTC
+++ acinclude.m4
@@ -221,7 +221,7 @@ if ( test [ "x$lookforldap" != "xno" ] || test [ "x$lo
         dnl See if we already have the paths we need in the environment.
 	dnl ...but only if --with-ldap was given without a specific path.
         if ( test [ "x$lookforldap" = "xyes" ] || test [ "x$lookforauthldap" = "xyes" ] ); then
-            AC_CHECK_HEADERS([ldap.h],[LDAPLIB="-lldap"], [LDAPLIB="failed"])
+            AC_CHECK_HEADERS([ldap.h],[LDAPLIB="-lldap_r"], [LDAPLIB="failed"])
             if test [ "x$LDAPLIB" != "xfailed" ]; then
                 break
             fi
@@ -233,7 +233,7 @@ if ( test [ "x$lookforldap" != "xno" ] || test [ "x$lo
             SAVE_CFLAGS=$CFLAGS
 	    dnl The headers might be in a funny place, so we need to use -Ipath
             CFLAGS="$CFLAGS -L$TEST_PATH $LDAPINC"
-            AC_CHECK_HEADERS([ldap.h],[LDAPLIB="-L$TEST_PATH -lldap"], [LDAPLIB="failed"])
+            AC_CHECK_HEADERS([ldap.h],[LDAPLIB="-L$TEST_PATH -lldap_r"], [LDAPLIB="failed"])
             CFLAGS=$SAVE_CFLAGS
             if test [ "x$LDAPLIB" != "xfailed" ]; then
                 break 2
@@ -247,7 +247,7 @@ if ( test [ "x$lookforldap" != "xno" ] || test [ "x$lo
         AC_MSG_ERROR([Could not find LDAP library.])
     else
         AC_DEFINE([AUTHLDAP], 1, [Define if LDAP will be used.])
-        AC_SEARCH_LIBS(ldap_initialize, ldap, AC_DEFINE([HAVE_LDAP_INITIALIZE], 1, [ldap_initialize() can be used instead of ldap_init()]))
+        AC_SEARCH_LIBS(ldap_initialize, ldap_r, AC_DEFINE([HAVE_LDAP_INITIALIZE], 1, [ldap_initialize() can be used instead of ldap_init()]))
         AC_SUBST(LDAPLIB)
         AC_SUBST(LDAPINC)
         AUTHALIB="modules/.libs/libauth_ldap.a"
@@ -291,6 +291,8 @@ AC_DEFUN([DM_CHECK_ZDB], [dnl
 		[ZDBLIB="-lzdb"], 
 		[ZDBLIB="failed"],
 	[[
+#include <stdbool.h>
+#include <zdb.h>
 #include <URL.h>
 #include <ResultSet.h>
 #include <PreparedStatement.h>
@@ -339,7 +341,7 @@ AC_DEFUN([DM_CHECK_EVENT], [
 
 AC_DEFUN([DM_CHECK_SSL], [
 	AC_CHECK_HEADERS([openssl/ssl.h],
-	 [SSLLIB=`pkg-config --libs openssl 2>/dev/null`],[SSLLIB="failed"])
+	 [SSLLIB="-lcrypto -lssl"],[SSLLIB="failed"])
 	if test [ "x$SSLLIB" = "xfailed" ]; then
 		AC_MSG_ERROR([Could not find OPENSSL library.])
 	else
@@ -539,15 +541,15 @@ AC_DEFUN([CMU_SOCKETS], [
 	save_LIBS="$LIBS"
 	SOCKETLIB=""
 	AC_CHECK_FUNC(connect, :,
-		AC_CHECK_LIB(nsl, gethostbyname,
-			     SOCKETLIB="-lnsl $SOCKETLIB")
-		AC_CHECK_LIB(socket, connect,
-			     SOCKETLIB="-lsocket $SOCKETLIB")
+		AC_CHECK_LIB(c, gethostbyname,
+			     SOCKETLIB="-lc $SOCKETLIB")
+		AC_CHECK_LIB(c, connect,
+			     SOCKETLIB="-lc $SOCKETLIB")
 	)
 	LIBS="$SOCKETLIB $save_LIBS"
 	AC_CHECK_FUNC(res_search, :,
-                AC_CHECK_LIB(resolv, res_search,
-                              SOCKETLIB="-lresolv $SOCKETLIB") 
+                AC_CHECK_LIB(c, res_search,
+                              SOCKETLIB="-lc $SOCKETLIB") 
         )
 	LIBS="$SOCKETLIB $save_LIBS"
 	AC_CHECK_FUNCS(dn_expand dns_lookup)
