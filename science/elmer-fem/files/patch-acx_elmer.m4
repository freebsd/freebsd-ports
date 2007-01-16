--- acx_elmer.m4.orig	Thu Mar 30 17:27:42 2006
+++ acx_elmer.m4	Tue Jan 16 11:00:48 2007
@@ -597,7 +597,7 @@
 
 # Generic UMFPACK library?
 if test $acx_umfpack_ok = no; then
-	AC_CHECK_LIB(umfpack, $umf4def, [acx_umfpack_ok=yes; UMFPACK_LIBS="-lumfpack -lamd"],,[-lamd])
+	AC_CHECK_LIB(umfpack_elmer, $umf4def, [acx_umfpack_ok=yes; UMFPACK_LIBS="-lumfpack_elmer -lamd_elmer"],,[-lamd_elmer])
 fi
 
 AC_SUBST(UMFPACK_LIBS)
@@ -1384,7 +1384,7 @@
   ;;
   *-*-freebsd*)
     SH_LD="$CC"
-    SH_LDFLAGS="-shared"
+    SH_LDFLAGS="-shared -fPIC"
   ;;
   alpha*-dec-osf*)
     SH_LDFLAGS="-shared"
