--- config/cryptominisat.m4.orig	2018-07-12 21:34:02 UTC
+++ config/cryptominisat.m4
@@ -36,7 +36,7 @@ elif test -n "$with_cryptominisat"; then
     AC_MSG_RESULT([no])
   fi
 
-  if ! test -d "$CRYPTOMINISAT_HOME" || ! test -x "$CRYPTOMINISAT_HOME/install/bin/cryptominisat5_simple" ; then
+  if ! test -d "$CRYPTOMINISAT_HOME" || ! test -x "$CRYPTOMINISAT_HOME/bin/cryptominisat5_simple" ; then
     AC_MSG_FAILURE([either $CRYPTOMINISAT_HOME is not an cryptominisat install tree or it's not yet built])
   fi
 
@@ -54,7 +54,7 @@ elif test -n "$with_cryptominisat"; then
     have_libcryptominisat=1
   fi
 
-  CRYPTOMINISAT_LDFLAGS="-L$CRYPTOMINISAT_HOME/install/lib"
+  CRYPTOMINISAT_LDFLAGS="-L$CRYPTOMINISAT_HOME/lib"
 
 else
   AC_MSG_RESULT([no, user didn't request cryptominisat])
@@ -74,8 +74,8 @@ if test -z "$CRYPTOMINISAT_LIBS"; then
   cvc4_save_LDFLAGS="$LDFLAGS"
   cvc4_save_CPPFLAGS="$CPPFLAGS"
 
-  LDFLAGS="-L$CRYPTOMINISAT_HOME/install/lib"
-  CPPFLAGS="$CPPFLAGS -I$CRYPTOMINISAT_HOME/install/include"
+  LDFLAGS="-L$CRYPTOMINISAT_HOME/lib"
+  CPPFLAGS="$CPPFLAGS -I$CRYPTOMINISAT_HOME/include"
   LIBS="-lcryptominisat5 $1"
 
   AC_LINK_IFELSE(
