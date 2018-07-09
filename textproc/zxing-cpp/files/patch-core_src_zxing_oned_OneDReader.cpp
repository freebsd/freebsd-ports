--- core/src/zxing/oned/OneDReader.cpp.orig	2018-03-20 15:08:49 UTC
+++ core/src/zxing/oned/OneDReader.cpp
@@ -21,6 +21,7 @@
 #include <zxing/oned/OneDResultPoint.h>
 #include <zxing/NotFoundException.h>
 #include <math.h>
+#include <float.h>
 #include <limits.h>
 #include <algorithm>
 #include <cfloat>
