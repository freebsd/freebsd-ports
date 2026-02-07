--- include/CombBLAS/FullyDistSpVec.cpp.orig	2022-07-15 16:37:18 UTC
+++ include/CombBLAS/FullyDistSpVec.cpp
@@ -37,8 +37,8 @@
 #include <sys/stat.h>
 
 #ifdef GNU_PARALLEL
-#include <parallel/algorithm>
-#include <parallel/numeric>
+#include <algorithm>
+//#include <parallel/numeric>
 #endif
 
 #include "usort/parUtils.h"
