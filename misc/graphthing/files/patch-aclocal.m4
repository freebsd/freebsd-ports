--- aclocal.m4.orig	Wed May  1 14:15:28 2002
+++ aclocal.m4	Wed May  1 14:16:29 2002
@@ -290,7 +290,7 @@
 		 CATOBJEXT=.cat
 		 INSTOBJEXT=.cat
 		 DATADIRNAME=lib
-		 INTLDEPS='$(top_builddir)/intl/libintl.a'
+		 dnl INTLDEPS='$(top_builddir)/intl/libintl.a'
 		 INTLLIBS=$INTLDEPS
 		 LIBS=`echo $LIBS | sed -e 's/-lintl//'`
 		 nls_cv_header_intl=intl/libintl.h
@@ -319,7 +319,7 @@
         CATOBJEXT=.gmo
         INSTOBJEXT=.mo
         DATADIRNAME=share
-	INTLDEPS='$(top_builddir)/intl/libintl.a'
+	dnl INTLDEPS='$(top_builddir)/intl/libintl.a'
 	INTLLIBS=$INTLDEPS
 	LIBS=`echo $LIBS | sed -e 's/-lintl//'`
         nls_cv_header_intl=intl/libintl.h
