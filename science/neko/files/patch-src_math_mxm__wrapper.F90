--- src/math/mxm_wrapper.F90.orig	2026-09-14 19:48:10 UTC
+++ src/math/mxm_wrapper.F90
@@ -13,15 +13,24 @@ module mxm_wrapper
   public :: mxm
 
   interface mxm_blas
-     module procedure mxm_blas_sp, mxm_blas_dp, mxm_blas_qp
+     module procedure mxm_blas_sp, mxm_blas_dp
+#ifdef HAVE_REAL128
+     module procedure mxm_blas_qp
+#endif
   end interface mxm_blas
 
   interface mxm_libxsmm
-     module procedure mxm_libxsmm_sp, mxm_libxsmm_dp, mxm_libxsmm_qp
+     module procedure mxm_libxsmm_sp, mxm_libxsmm_dp
+#ifdef HAVE_REAL128
+     module procedure mxm_libxsmm_qp
+#endif
   end interface mxm_libxsmm
 
-  private :: mxm_blas_sp, mxm_blas_dp, mxm_blas_qp
-  private :: mxm_libxsmm_sp, mxm_libxsmm_dp, mxm_libxsmm_qp
+  private :: mxm_blas_sp, mxm_blas_dp
+  private :: mxm_libxsmm_sp, mxm_libxsmm_dp
+#ifdef HAVE_REAL128
+  private :: mxm_blas_qp, mxm_libxsmm_qp
+#endif
 
 contains
 
@@ -61,6 +70,7 @@ contains
 
   end subroutine mxm_blas_dp
 
+#ifdef HAVE_REAL128
   subroutine mxm_blas_qp(a, n1, b, n2, c, n3)
     integer, intent(in) :: n1, n2, n3
     real(kind=qp), intent(in) :: a(n1, n2)
@@ -70,6 +80,7 @@ contains
     call neko_error('Not implemented yet!')
 
   end subroutine mxm_blas_qp
+#endif
 
   subroutine mxm_libxsmm_sp(a, n1, b, n2, c, n3)
     integer, intent(in) :: n1, n2, n3
@@ -105,6 +116,7 @@ contains
 #endif
   end subroutine mxm_libxsmm_dp
 
+#ifdef HAVE_REAL128
   subroutine mxm_libxsmm_qp(a, n1, b, n2, c, n3)
     integer, intent(in) :: n1, n2, n3
     real(kind=qp), intent(in) :: a(n1, n2)
@@ -114,5 +126,6 @@ contains
     call neko_error('Not implemented yet!')
 
   end subroutine mxm_libxsmm_qp
+#endif
 
 end module mxm_wrapper
