--- ext/sybase_ct/config.m4.orig	Wed Mar 28 05:34:43 2001
+++ ext/sybase_ct/config.m4	Fri Oct 26 21:35:50 2001
@@ -20,16 +20,12 @@
     fi
 	PHP_ADD_INCLUDE($SYBASE_CT_INCDIR)
 	PHP_ADD_LIBPATH($SYBASE_CT_LIBDIR)
-	PHP_ADD_LIBRARY(cs)
 	PHP_ADD_LIBRARY(ct)
-	PHP_ADD_LIBRARY(comn)
-	PHP_ADD_LIBRARY(intl)
-	SYBASE_CT_LIBS="-lcs -lct -lcomn -lintl"
+	SYBASE_CT_LIBS="-lct"
     old_LDFLAGS=$LDFLAGS
     LDFLAGS="$LDFLAGS -L$SYBASE_CT_LIBDIR"
     AC_CHECK_LIB(tcl, netg_errstr,
               [ PHP_ADD_LIBRARY(tcl) ],
-              [ PHP_ADD_LIBRARY(sybtcl) ],
               [ $SYBASE_CT_LIBS ])
     AC_CHECK_LIB(insck, insck__getVdate,
               [ PHP_ADD_LIBRARY(insck) ])
