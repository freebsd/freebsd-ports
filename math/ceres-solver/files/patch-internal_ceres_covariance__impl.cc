- backport of the commit Enable compatibility with SuiteSparse 7.2.0 
- see https://github.com/ceres-solver/ceres-solver/commit/9cca671273c2f205ca7350422f48b7b119c5dd78

--- internal/ceres/covariance_impl.cc.orig	2023-09-20 07:40:12 UTC
+++ internal/ceres/covariance_impl.cc
@@ -630,7 +630,7 @@ bool CovarianceImpl::ComputeCovarianceValuesUsingSuite
   // separately.
   const SuiteSparse_long rank = SuiteSparseQR<double>(SPQR_ORDERING_BESTAMD,
                                                       SPQR_DEFAULT_TOL,
-                                                      cholmod_jacobian.ncol,
+                                                      static_cast<int64_t>(cholmod_jacobian.ncol),
                                                       &cholmod_jacobian,
                                                       &R,
                                                       &permutation,
