--- Eigen/src/Core/products/Parallelizer.h.orig	2020-10-05 11:24:15 UTC
+++ Eigen/src/Core/products/Parallelizer.h
@@ -132,8 +132,7 @@ void parallelize_gemm(const Functor& func, Index rows,
 
   ei_declare_aligned_stack_constructed_variable(GemmParallelInfo<Index>,info,threads,0);
 
-  int errorCount = 0;
-  #pragma omp parallel num_threads(threads) reduction(+: errorCount)
+  #pragma omp parallel num_threads(threads)
   {
     Index i = omp_get_thread_num();
     // Note that the actual number of threads might be lower than the number of request ones.
@@ -152,14 +151,11 @@ void parallelize_gemm(const Functor& func, Index rows,
     info[i].lhs_start = r0;
     info[i].lhs_length = actualBlockRows;
 
-    EIGEN_TRY {
-      if(transpose) func(c0, actualBlockCols, 0, rows, info);
-      else          func(0, rows, c0, actualBlockCols, info);
-    } EIGEN_CATCH(...) {
-      ++errorCount;
-    }
+    if(transpose)
+      func(c0, actualBlockCols, 0, rows, info);
+    else
+      func(0, rows, c0, actualBlockCols, info);
   }
-  if (errorCount) EIGEN_THROW_X(Eigen::eigen_assert_exception());
 #endif
 }
 
