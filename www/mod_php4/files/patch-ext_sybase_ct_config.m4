--- ext/sybase_ct/config.m4.orig	Fri Nov 30 23:12:31 2001
+++ ext/sybase_ct/config.m4	Tue Apr 23 21:53:54 2002
@@ -30,17 +30,12 @@
     PHP_ADD_LIBRARY(ct,, SYBASE_CT_SHARED_LIBADD)
     SYBASE_CT_LIBS="-L$SYBASE_CT_LIBDIR -lct"
   else
-    PHP_ADD_LIBRARY(cs,, SYBASE_CT_SHARED_LIBADD)
     PHP_ADD_LIBRARY(ct,, SYBASE_CT_SHARED_LIBADD)
-    PHP_ADD_LIBRARY(comn,, SYBASE_CT_SHARED_LIBADD)
-    PHP_ADD_LIBRARY(intl,, SYBASE_CT_SHARED_LIBADD)
   
-    SYBASE_CT_LIBS="-L$SYBASE_CT_LIBDIR -lcs -lct -lcomn -lintl"
+    SYBASE_CT_LIBS="-L$SYBASE_CT_LIBDIR -lct"
   
     PHP_CHECK_LIBRARY(tcl, netg_errstr, [
       PHP_ADD_LIBRARY(tcl,,SYBASE_CT_SHARED_LIBADD)
-    ],[ 
-      PHP_ADD_LIBRARY(sybtcl,,SYBASE_CT_SHARED_LIBADD)
     ],[ 
       $SYBASE_CT_LIBS 
     ])
