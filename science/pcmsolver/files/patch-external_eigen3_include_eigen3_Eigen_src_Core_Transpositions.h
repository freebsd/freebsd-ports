- fix build error with Eigen 3.3.2


--- external/eigen3/include/eigen3/Eigen/src/Core/Transpositions.h.orig	2025-10-15 01:10:00 UTC
+++ external/eigen3/include/eigen3/Eigen/src/Core/Transpositions.h
@@ -384,7 +384,7 @@ class Transpose<TranspositionsBase<TranspositionsDeri
     const Product<OtherDerived, Transpose, AliasFreeProduct>
     operator*(const MatrixBase<OtherDerived>& matrix, const Transpose& trt)
     {
-      return Product<OtherDerived, Transpose, AliasFreeProduct>(matrix.derived(), trt.derived());
+      return Product<OtherDerived, Transpose, AliasFreeProduct>(matrix.derived(), trt);
     }
 
     /** \returns the \a matrix with the inverse transpositions applied to the rows.
