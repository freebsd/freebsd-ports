--- packages/arb-avm-cpp/avm_values/include/avm_values/bigint.hpp.orig	2022-01-14 20:18:32 UTC
+++ packages/arb-avm-cpp/avm_values/include/avm_values/bigint.hpp
@@ -17,9 +17,14 @@
 #ifndef bigint_hpp
 #define bigint_hpp
 
+#include <gsl/gsl>
+
 #include <intx/intx.hpp>
 
+#include <array>
 #include <vector>
+
+using namespace gsl;
 
 using uint256_t = intx::uint256;
 using uint512_t = intx::uint512;
