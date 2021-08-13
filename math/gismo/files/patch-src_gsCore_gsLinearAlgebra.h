--- src/gsCore/gsLinearAlgebra.h.orig	2021-08-13 01:12:20 UTC
+++ src/gsCore/gsLinearAlgebra.h
@@ -84,7 +84,7 @@ using Eigen::internal::cast; // from Core/MathFunction
    and https://en.wikipedia.org/wiki/NaN
  */
 template<typename Derived>
-inline bool isnumber(const Eigen::MatrixBase<Derived>& x)
+inline bool isnumber_x(const Eigen::MatrixBase<Derived>& x)
 { return ((x.array() == x.array())).all(); }
 
 /**
