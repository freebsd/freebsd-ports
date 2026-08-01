--- src/operators/math/common.hpp.orig	2023-11-08 01:08:28 UTC
+++ src/operators/math/common.hpp
@@ -29,8 +29,21 @@
 #include "lbann/base.hpp"
 #include "lbann/utils/profiling.hpp"
 
+#include <cmath>
+
 namespace lbann {
 namespace internal {
+
+template <typename T>
+inline bool isnan(T const& x)
+{
+  return std::isnan(x);
+}
+
+inline bool isnan(half_float::half const& x)
+{
+  return std::isnan(static_cast<float>(x));
+}
 
 /** @brief A binary entrywise map c <- f(a,b).
  */
