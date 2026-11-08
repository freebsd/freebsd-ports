--- include/TFEL/Material/Eshelby.ixx.orig	2025-05-12 12:05:33 UTC
+++ include/TFEL/Material/Eshelby.ixx
@@ -18,6 +18,17 @@
 #include <stdexcept>
 #include <typeinfo>
 
+// On FreeBSD clang has no std::ellint_1 / ellint_2
+#if !defined(__cpp_lib_math_special_functions) && !defined(__STDCPP_MATH_SPEC_FUNCS__)
+#include <boost/math/special_functions/ellint_1.hpp>
+#include <boost/math/special_functions/ellint_2.hpp>
+#define TFEL_ELLINT_1 boost::math::ellint_1
+#define TFEL_ELLINT_2 boost::math::ellint_2
+#else
+#define TFEL_ELLINT_1 std::ellint_1
+#define TFEL_ELLINT_2 std::ellint_2
+#endif
+
 namespace tfel::material::homogenization::elasticity {
 
   template <typename real>
@@ -232,8 +243,8 @@ namespace tfel::material::homogenization::elasticity {
     const auto R = (1 - 2 * nu) / 8 / pi / (1 - nu);
     const auto k = std::sqrt((a2 - b2) / (a2 - c2));
     const auto theta = std::asin(std::sqrt(1 - c2 / a2));
-    const auto F = std::ellint_1(k, theta);
-    const auto E = std::ellint_2(k, theta);
+    const auto F = TFEL_ELLINT_1(k, theta);
+    const auto E = TFEL_ELLINT_2(k, theta);
 
     const auto Ia = 4 * pi * a_ * b_ * c_ / (a2 - b2) / a_ /
                     std::sqrt(1 - c2 / a2) * (F - E);
