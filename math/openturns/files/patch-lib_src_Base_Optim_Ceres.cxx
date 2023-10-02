--- lib/src/Base/Optim/Ceres.cxx.orig	2022-11-08 10:49:19 UTC
+++ lib/src/Base/Optim/Ceres.cxx
@@ -341,8 +341,6 @@ void Ceres::run()
       throw InvalidArgumentException(HERE) << "Invalid value for sparse_linear_algebra_library_type";
     if (ResourceMap::HasKey("Ceres-use_explicit_schur_complement"))
       options.use_explicit_schur_complement = ResourceMap::GetAsBool("Ceres-use_explicit_schur_complement");
-    if (ResourceMap::HasKey("Ceres-use_postordering"))
-      options.use_postordering = ResourceMap::GetAsBool("Ceres-use_postordering");
     if (ResourceMap::HasKey("Ceres-dynamic_sparsity"))
       options.dynamic_sparsity = ResourceMap::GetAsBool("Ceres-dynamic_sparsity");
     if (ResourceMap::HasKey("Ceres-min_linear_solver_iterations"))
