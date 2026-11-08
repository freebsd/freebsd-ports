--- source/base/mpi.cc.orig	2026-09-16 18:38:24 UTC
+++ source/base/mpi.cc
@@ -17,7 +17,9 @@
 
 #include <hyper.deal/base/mpi.h>
 #include <hyper.deal/base/utilities.h>
-#include <immintrin.h>
+#ifdef __AVX2__
+#  include <immintrin.h>
+#endif
 
 #include <algorithm>
 #include <bitset>
