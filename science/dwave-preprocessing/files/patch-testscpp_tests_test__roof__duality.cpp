--- testscpp/tests/test_roof_duality.cpp.orig	2023-07-06 22:19:16 UTC
+++ testscpp/tests/test_roof_duality.cpp
@@ -14,7 +14,7 @@
 
 #include <dimod/quadratic_model.h>
 
-#include "catch2/catch.hpp"
+#include <catch2/catch.hpp>
 #include "dwave-preprocessing/fix_variables.hpp"
 
 namespace fix_variables_ {
