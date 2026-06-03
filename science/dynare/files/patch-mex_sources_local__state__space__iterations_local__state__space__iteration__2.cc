-- FreeBSD compatibility: replace C++17 structured bindings with named tuple references.
-- Clang's OpenMP implementation does not support capturing structured bindings in parallel
-- regions (structured bindings have no address in the OpenMP data-sharing model).

--- mex/sources/local_state_space_iterations/local_state_space_iteration_2.cc.orig	2025-03-19 00:00:00 UTC
+++ mex/sources/local_state_space_iterations/local_state_space_iteration_2.cc	2025-03-19 00:00:00 UTC
@@ -69,8 +69,15 @@
   const double one = 1.0;
   const blas_int ONE = 1;
 #endif
-  auto [ii1, ii2, ii3] = set_vector_of_indices(n, m); // vector indices for ghxx
-  auto [jj1, jj2, jj3] = set_vector_of_indices(q, m); // vector indices for ghuu
+  // Use named tuple variables instead of structured bindings (clang OpenMP limitation)
+  auto ghxx_indices = set_vector_of_indices(n, m);
+  const auto& ii1 = std::get<0>(ghxx_indices);
+  const auto& ii2 = std::get<1>(ghxx_indices);
+  const auto& ii3 = std::get<2>(ghxx_indices);
+  auto ghuu_indices = set_vector_of_indices(q, m);
+  const auto& jj1 = std::get<0>(ghuu_indices);
+  const auto& jj2 = std::get<1>(ghuu_indices);
+  const auto& jj3 = std::get<2>(ghuu_indices);
 #pragma omp parallel for num_threads(number_of_threads)
   for (int particle = 0; particle < s; particle++)
     {
@@ -148,8 +155,15 @@
   const double one = 1.0;
   const blas_int ONE = 1;
 #endif
-  auto [ii1, ii2, ii3] = set_vector_of_indices(n, m); // vector indices for ghxx
-  auto [jj1, jj2, jj3] = set_vector_of_indices(q, m); // vector indices for ghuu
+  // Use named tuple variables instead of structured bindings (clang OpenMP limitation)
+  auto ghxx_indices = set_vector_of_indices(n, m);
+  const auto& ii1 = std::get<0>(ghxx_indices);
+  const auto& ii2 = std::get<1>(ghxx_indices);
+  const auto& ii3 = std::get<2>(ghxx_indices);
+  auto ghuu_indices = set_vector_of_indices(q, m);
+  const auto& jj1 = std::get<0>(ghuu_indices);
+  const auto& jj2 = std::get<1>(ghuu_indices);
+  const auto& jj3 = std::get<2>(ghuu_indices);
 #pragma omp parallel for num_threads(number_of_threads)
   for (int particle = 0; particle < s; particle++)
     {
