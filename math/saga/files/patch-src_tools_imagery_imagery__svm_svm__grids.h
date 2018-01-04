--- src/tools/imagery/imagery_svm/svm_grids.h.orig	2017-01-29 14:18:09 UTC
+++ src/tools/imagery/imagery_svm/svm_grids.h
@@ -73,7 +73,7 @@
 #include "MLB_Interface.h"
 
 #if defined(SYSTEM_SVM)
-#include <libsvm/svm.h>
+#include <svm.h>
 #else
 #include "svm/svm.h"
 #endif
