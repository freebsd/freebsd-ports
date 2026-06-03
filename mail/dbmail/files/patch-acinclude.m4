--- acinclude.m4.orig	2025-05-31 16:37:09 UTC
+++ acinclude.m4
@@ -43,7 +43,7 @@ AC_DEFINE_UNQUOTED([DM_VERSION], "$PACKAGE_VERSION", [
 AC_DEFINE_UNQUOTED([DM_PWD], "$ac_pwd", [Build directory])
 AC_DEFINE_UNQUOTED([DM_VERSION], "$PACKAGE_VERSION", [DBMail Version])
 ])
-	
+
 AC_DEFUN([DM_SET_SHARED_OR_STATIC], [dnl
 if test [ "$enable_shared" = "yes" -a "$enable_static" = "yes" ]; then
      AC_MSG_ERROR([
@@ -89,7 +89,7 @@ if test [ "x$lookforsieve" != "xno" ]; then
     fi
     AC_MSG_CHECKING([for libSieve headers])
     STOP_LOOKING_FOR_SIEVE=""
-    while test [ -z $STOP_LOOKING_FOR_SIEVE ]; do 
+    while test [ -z $STOP_LOOKING_FOR_SIEVE ]; do
 
 	if test [ "x$lookforsieve" = "xyes" ]; then
             DM_SIEVE_INC([SIEVEINC=""], [SIEVEINC="failed"])
@@ -97,7 +97,7 @@ if test [ "x$lookforsieve" != "xno" ]; then
                 break
             fi
         fi
- 
+
         for TEST_PATH in $sieveprefixes; do
 	    TEST_PATH="$TEST_PATH/include"
             SAVE_CFLAGS=$CFLAGS
@@ -120,7 +120,7 @@ if test [ "x$lookforsieve" != "xno" ]; then
 
     AC_MSG_CHECKING([for libSieve libraries])
     STOP_LOOKING_FOR_SIEVE=""
-    while test [ -z $STOP_LOOKING_FOR_SIEVE ]; do 
+    while test [ -z $STOP_LOOKING_FOR_SIEVE ]; do
 
         if test [ "x$lookforsieve" = "xyes" ]; then
             DM_SIEVE_LIB([SIEVELIB="-lsieve"], [SIEVELIB="failed"])
@@ -128,7 +128,7 @@ if test [ "x$lookforsieve" != "xno" ]; then
                 break
             fi
         fi
- 
+
         for TEST_PATH in $sieveprefixes; do
 	    TEST_PATH="$TEST_PATH/lib"
             SAVE_CFLAGS=$CFLAGS
@@ -186,7 +186,7 @@ if ( test [ "x$lookforldap" != "xno" ] || test [ "x$lo
     fi
 
     STOP_LOOKING_FOR_LDAP=""
-    while test [ -z $STOP_LOOKING_FOR_LDAP ]; do 
+    while test [ -z $STOP_LOOKING_FOR_LDAP ]; do
 
         dnl See if we already have the paths we need in the environment.
 	dnl ...but only if --with-ldap was given without a specific path.
@@ -196,7 +196,7 @@ if ( test [ "x$lookforldap" != "xno" ] || test [ "x$lo
                 break
             fi
         fi
- 
+
         dnl Explicitly test paths from --with-ldap or configure.in
         for TEST_PATH in $ldapprefixes; do
 	    TEST_PATH="$TEST_PATH/include"
@@ -217,7 +217,7 @@ if ( test [ "x$lookforldap" != "xno" ] || test [ "x$lo
     fi
 
     STOP_LOOKING_FOR_LDAP=""
-    while test [ -z $STOP_LOOKING_FOR_LDAP ]; do 
+    while test [ -z $STOP_LOOKING_FOR_LDAP ]; do
 
         dnl See if we already have the paths we need in the environment.
 	dnl ...but only if --with-ldap was given without a specific path.
@@ -227,7 +227,7 @@ if ( test [ "x$lookforldap" != "xno" ] || test [ "x$lo
                 break
             fi
         fi
- 
+
         dnl Explicitly test paths from --with-ldap or configure.in
         for TEST_PATH in $ldapprefixes; do
 	    TEST_PATH="$TEST_PATH/lib"
@@ -261,14 +261,14 @@ AC_DEFUN([DM_CHECK_JEMALLOC], [dnl
 	AC_ARG_WITH(jemalloc,[  --with-jemalloc=PATH	  path to libjemalloc base directory (e.g. /usr/local or /usr)],
 		[lookforjemalloc="$withval"],[lookforjemalloc="yes"])
 	if test [ "x$lookforjemalloc" != "xno" ] ; then
-		if test [ "x$lookforjemalloc" = "xyes" ] ; then 
+		if test [ "x$lookforjemalloc" = "xyes" ] ; then
 			CFLAGS="$CFLAGS -I${ac_default_prefix}/include/jemalloc -I/usr/include/jemalloc"
 		else
 			CFLAGS="$CFLAGS -I${lookforjemalloc}/include/jemalloc"
 		fi
 	fi
 	AC_CHECK_HEADERS([jemalloc.h],
-		[JEMALLOCLIB="-ljemalloc"], 
+		[JEMALLOCLIB="-ljemalloc"],
 		[JEMALLOCLIB="no"],
 	[[
 #include <jemalloc.h>
@@ -285,13 +285,13 @@ AC_DEFUN([DM_CHECK_ZDB], [dnl
 	if test [ "x$lookforzdb" = "xno" ] ; then
 		CFLAGS="$CFLAGS -I${ac_default_prefix}/include/zdb -I/usr/include/zdb"
 	else
-		CFLAGS="$CFLAGS -I${lookforzdb}/include/zdb"
+		CFLAGS="$CFLAGS -I${lookforzdb}/include -I${lookforzdb}/include/zdb"
 	fi
-	AC_CHECK_HEADERS([zdb.h],
-		[ZDBLIB="-lzdb"], 
+	AC_CHECK_HEADERS([zdb/zdb.h],
+		[ZDBLIB="-lzdb"],
 		[ZDBLIB="failed"],
 	[[
-         #include <zdb.h>
+         #include <zdb/zdb.h>
 	]])
 	if test [ "x$ZDBLIB" = "xfailed" ]; then
 		AC_MSG_ERROR([Could not find ZDB library.])
@@ -334,7 +334,7 @@ AC_DEFUN([DM_CHECK_SSL], [
 
 AC_DEFUN([DM_CHECK_SSL], [
 	AC_CHECK_HEADERS([openssl/ssl.h],
-	 [SSLLIB=`pkg-config --libs openssl 2>/dev/null`],[SSLLIB="failed"])
+	 [SSLLIB="-lcrypto -lssl"],[SSLLIB="failed"])
 	if test [ "x$SSLLIB" = "xfailed" ]; then
 		AC_MSG_ERROR([Could not find OPENSSL library.])
 	else
@@ -389,7 +389,7 @@ else
 		AC_MSG_RESULT([no])
 		AC_MSG_ERROR([Unable to locate glib development files])
 	fi
- 
+
 	CFLAGS="$CFLAGS $ac_glib_cflags"
 	AC_MSG_RESULT([$ac_glib_cflags])
         AC_MSG_CHECKING([Glib libraries])
@@ -428,7 +428,7 @@ else
 		CFLAGS="$CFLAGS $ac_gmime_cflags"
 		AC_MSG_RESULT([$ac_gmime_cflags])
 	fi
-	
+
         AC_MSG_CHECKING([GMime libraries])
 	ac_gmime_libs=`${gmimeconfig} --libs gmime-3.0 2>/dev/null|| ${gmimeconfig} --libs gmime-3.0 2>/dev/null`
 	if test -z "$ac_gmime_libs"
@@ -447,7 +447,7 @@ AC_DEFUN([DM_PATH_CHECK],[dnl
   [  --with-check=PATH       prefix where check is installed [default=auto]],
   [test x"$with_check" = xno && with_check="no"],
   [with_check="no"])
-  
+
 if test "x$with_check" != xno; then
 	AC_PATH_PROG(checkconfig,pkg-config)
 	if test [ -z "$checkconfig" ]
@@ -546,15 +546,15 @@ AC_DEFUN([CMU_SOCKETS], [
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
@@ -611,19 +611,19 @@ AC_DEFUN([DM_UPGRADE_STEPS], [dnl
 	PGSQL_32004=`sed -e 's/\"/\\\"/g' -e 's/^/\"/' -e 's/$/\\\n\"/' -e '$!s/$/ \\\\/'  sql/postgresql/upgrades/32004.psql`
 	MYSQL_32004=`sed -e 's/\"/\\\"/g' -e 's/^/\"/' -e 's/$/\\\n\"/' -e '$!s/$/ \\\\/'  sql/mysql/upgrades/32004.mysql`
 	SQLITE_32004=`sed -e 's/\"/\\\"/g' -e 's/^/\"/' -e 's/$/\\\n\"/' -e '$!s/$/ \\\\/'  sql/sqlite/upgrades/32004.sqlite`
-	
+
 	AC_SUBST(PGSQL_32004)
 	AC_SUBST(MYSQL_32004)
 	AC_SUBST(SQLITE_32004)
-	
+
 	PGSQL_32005=`sed -e 's/\"/\\\"/g' -e 's/^/\"/' -e 's/$/\\\n\"/' -e '$!s/$/ \\\\/'  sql/postgresql/upgrades/32005.psql`
 	MYSQL_32005=`sed -e 's/\"/\\\"/g' -e 's/^/\"/' -e 's/$/\\\n\"/' -e '$!s/$/ \\\\/'  sql/mysql/upgrades/32005.mysql`
 	SQLITE_32005=`sed -e 's/\"/\\\"/g' -e 's/^/\"/' -e 's/$/\\\n\"/' -e '$!s/$/ \\\\/'  sql/sqlite/upgrades/32005.sqlite`
-	
+
 	AC_SUBST(PGSQL_32005)
 	AC_SUBST(MYSQL_32005)
 	AC_SUBST(SQLITE_32005)
-	
+
 	PGSQL_32006=`sed -e 's/\"/\\\"/g' -e 's/^/\"/' -e 's/$/\\\n\"/' -e '$!s/$/ \\\\/'  sql/postgresql/upgrades/32006.psql`
 	MYSQL_32006=`sed -e 's/\"/\\\"/g' -e 's/^/\"/' -e 's/$/\\\n\"/' -e '$!s/$/ \\\\/'  sql/mysql/upgrades/32006.mysql`
 	SQLITE_32006=`sed -e 's/\"/\\\"/g' -e 's/^/\"/' -e 's/$/\\\n\"/' -e '$!s/$/ \\\\/'  sql/sqlite/upgrades/32006.sqlite`
