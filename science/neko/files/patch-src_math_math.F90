--- src/math/math.F90.orig	2026-09-14 19:48:10 UTC
+++ src/math/math.F90
@@ -76,7 +76,10 @@ module math
   real(kind=rp), public, parameter :: pi = 4._rp*atan(1._rp)
 
   interface abscmp
-     module procedure sabscmp, dabscmp, qabscmp
+     module procedure sabscmp, dabscmp
+#ifdef HAVE_REAL128
+     module procedure qabscmp
+#endif
   end interface abscmp
 
   interface sort
@@ -96,7 +99,10 @@ module math
   end interface flipv
 
   interface relcmp
-     module procedure srelcmp, drelcmp, qrelcmp
+     module procedure srelcmp, drelcmp
+#ifdef HAVE_REAL128
+     module procedure qrelcmp
+#endif
   end interface relcmp
 
   public :: abscmp, rzero, izero, row_zero, rone, copy, cmult, cadd, cfill, &
@@ -145,6 +151,7 @@ contains
 
   end function dabscmp
 
+#ifdef HAVE_REAL128
   !> Return double precision absolute comparison \f$ | x - y | < \epsilon \f$
   pure function qabscmp(x, y, tol)
     real(kind=qp), intent(in) :: x
@@ -159,6 +166,7 @@ contains
     end if
 
   end function qabscmp
+#endif
 
   !> Return single precision relative comparison
   !! \f$ | x - y |<= \epsilon*|y| \f$
@@ -191,6 +199,7 @@ contains
   end function drelcmp
 
 
+#ifdef HAVE_REAL128
   !> Return quad precision relative comparison \f$ | x - y |/|y| < \epsilon \f$
   pure function qrelcmp(x, y, eps)
     real(kind=qp), intent(in) :: x
@@ -204,6 +213,7 @@ contains
     end if
 
   end function qrelcmp
+#endif
 
   !> Approximate the principal real branch of the Lambert W function for
   !! non-negative real x.
