--- src/math/fdm.F90.orig	2026-09-14 19:48:10 UTC
+++ src/math/fdm.F90
@@ -102,7 +102,10 @@ module fdm
   end type fdm_t
 
   interface sygv
-     module procedure sp_sygv, dp_sygv, qp_sygv
+     module procedure sp_sygv, dp_sygv
+#ifdef HAVE_REAL128
+     module procedure qp_sygv
+#endif
   end interface sygv
 
 contains
@@ -457,6 +460,7 @@ contains
     call dsygv(1, 'V', 'U', n, a, n, b, n, lam, bw, lbw, info)
   end subroutine dp_sygv
 
+#ifdef HAVE_REAL128
   subroutine qp_sygv(a, b, lam, n, lx, bw, lbw)
     integer, intent(in) :: n, lx, lbw
     real(kind=qp), intent(inout) :: a(n, n), b(n, n), lam(n)
@@ -478,6 +482,7 @@ contains
     end if
 
   end subroutine qp_sygv
+#endif
 
   subroutine fdm_setup_fast1d_a(a, lbc, rbc, ll, lm, lr, ah, n)
     integer, intent(in) ::lbc, rbc, n
