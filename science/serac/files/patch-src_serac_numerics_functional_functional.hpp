--- src/serac/numerics/functional/functional.hpp.orig	2022-09-05 06:55:45 UTC
+++ src/serac/numerics/functional/functional.hpp
@@ -23,6 +23,8 @@
 #include "serac/numerics/functional/boundary_integral.hpp"
 #include "serac/numerics/functional/dof_numbering.hpp"
 
+#include <array>
+
 namespace serac {
 
 template <int i>
