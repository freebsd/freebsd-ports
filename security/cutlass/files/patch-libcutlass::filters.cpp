--- libcutlass/filters.cpp.orig	Wed Dec 28 19:49:13 2005
+++ libcutlass/filters.cpp	Wed Dec 28 19:49:19 2005
@@ -5,6 +5,7 @@
 #include <cutlass/filters.hpp>
 #include <botan/rng.h>
 #include <botan/lookup.h>
+#include <botan/bit_ops.h>
 using namespace Botan;
 
 static void dump(const char* name, const SecureVector<byte>& x)
