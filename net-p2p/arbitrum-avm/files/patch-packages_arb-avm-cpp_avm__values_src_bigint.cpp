--- packages/arb-avm-cpp/avm_values/src/bigint.cpp.orig	2022-01-14 20:19:00 UTC
+++ packages/arb-avm-cpp/avm_values/src/bigint.cpp
@@ -18,6 +18,7 @@
 
 #include <ethash/keccak.hpp>
 
+#include <array>
 #include <sstream>
 #include <vector>
 
