--- src/cpp/flann/algorithms/kdtree_index.h.orig	2013-01-16 06:38:32 UTC
+++ src/cpp/flann/algorithms/kdtree_index.h
@@ -36,6 +36,7 @@
 #include <cassert>
 #include <cstring>
 #include <stdarg.h>
+#include <math.h>
 
 #include "flann/general.h"
 #include "flann/algorithms/nn_index.h"
@@ -663,7 +664,7 @@ private:
             ElementType max_span = 0;
             size_t div_feat = 0;
             for (size_t i=0;i<veclen_;++i) {
-                ElementType span = abs(point[i]-leaf_point[i]);
+                ElementType span = fabs(point[i]-leaf_point[i]);
                 if (span > max_span) {
                     max_span = span;
                     div_feat = i;
