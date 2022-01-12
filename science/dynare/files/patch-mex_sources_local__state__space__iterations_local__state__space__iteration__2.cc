- workaround for https://bugs.llvm.org/show_bug.cgi?id=49238

--- mex/sources/local_state_space_iterations/local_state_space_iteration_2.cc.orig	2022-01-10 23:38:14 UTC
+++ mex/sources/local_state_space_iterations/local_state_space_iteration_2.cc
@@ -61,8 +61,14 @@ ss2Iteration_pruning(double *y2, double *y1, const dou
   const double one = 1.0;
   const blas_int ONE = 1;
 #endif
-  auto [ii1, ii2, ii3] = set_vector_of_indices(n, m); // vector indices for ghxx
-  auto [jj1, jj2, jj3] = set_vector_of_indices(q, m); // vector indices for ghuu
+  auto [ii1_, ii2_, ii3_] = set_vector_of_indices(n, m); // vector indices for ghxx
+  auto ii1 = ii1_;
+  auto ii2 = ii2_;
+  auto ii3 = ii3_;
+  auto [jj1_, jj2_, jj3_] = set_vector_of_indices(q, m); // vector indices for ghuu
+  auto jj1 = jj1_;
+  auto jj2 = jj2_;
+  auto jj3 = jj3_;
 #pragma omp parallel for num_threads(number_of_threads)
   for (int particle = 0; particle < s; particle++)
     {
@@ -139,8 +145,14 @@ ss2Iteration(double *y, const double *yhat, const doub
   const double one = 1.0;
   const blas_int ONE = 1;
 #endif
-  auto [ii1, ii2, ii3] = set_vector_of_indices(n, m); // vector indices for ghxx
-  auto [jj1, jj2, jj3] = set_vector_of_indices(q, m); // vector indices for ghuu
+  auto [ii1_, ii2_, ii3_] = set_vector_of_indices(n, m); // vector indices for ghxx
+  auto ii1 = ii1_;
+  auto ii2 = ii2_;
+  auto ii3 = ii3_;
+  auto [jj1_, jj2_, jj3_] = set_vector_of_indices(q, m); // vector indices for ghuu
+  auto jj1 = jj1_;
+  auto jj2 = jj2_;
+  auto jj3 = jj3_;
 #pragma omp parallel for num_threads(number_of_threads)
   for (int particle = 0; particle < s; particle++)
     {
