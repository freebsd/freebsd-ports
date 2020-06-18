--- build/pkgs/flint/spkg-configure.m4.orig	2020-06-18 13:10:54 UTC
+++ build/pkgs/flint/spkg-configure.m4
@@ -13,11 +13,6 @@ SAGE_SPKG_CONFIGURE([flint], [
             AC_SEARCH_LIBS([fmpz_poly_get_ZZX], [flint], [
 
               AC_MSG_CHECKING([that GC is not enabled in Flint... ])
-              AC_RUN_IFELSE([
-                 AC_LANG_PROGRAM([[#include <flint/flint.h>]], [[return HAVE_GC;]])],
-                 [AC_MSG_RESULT([GC not enabled. Good.])],
-		        [AC_MSG_RESULT([GC enabled. Incompatible with Sage.])
-		         sage_spkg_install_flint=yes])
             ], [sage_spkg_install_flint=yes])
           ], [sage_spkg_install_flint=yes])
         ], [sage_spkg_install_flint=yes])
