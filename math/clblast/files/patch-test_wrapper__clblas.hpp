--- test/wrapper_clblas.hpp.orig	2026-03-30 17:50:42 UTC
+++ test/wrapper_clblas.hpp
@@ -16,6 +16,9 @@
 #include <cstddef>
 
 #include "clblast.h"
+// Patch from https://github.com/CNugteren/CLBlast/commit/eeff251463434753470bccc16f2879437c220808
+#include "clblast_half.h"
+#include "test/test_utilities.hpp"
 #include "utilities/backend.hpp"
 #include "utilities/utilities.hpp"
 
