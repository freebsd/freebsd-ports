--- src/ml/ml_kmeans.cc.orig	2025-01-02 17:07:23 UTC
+++ src/ml/ml_kmeans.cc
@@ -2,7 +2,7 @@
 
 #include "ml_kmeans.h"
 #include "libnetdata/libnetdata.h"
-#include "dlib/dlib/clustering.h"
+#include "dlib/clustering.h"
 
 void
 ml_kmeans_init(ml_kmeans_t *kmeans)
