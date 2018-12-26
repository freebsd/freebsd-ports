--- src/tools/imagery/imagery_svm/svm_grids.h.orig	2018-11-22 07:53:06 UTC
+++ src/tools/imagery/imagery_svm/svm_grids.h
@@ -72,7 +72,7 @@
 #include "MLB_Interface.h"
 
 #if defined(SYSTEM_SVM)
-#include <libsvm/svm.h>
+#include <svm.h>
 #else
 #include "svm/svm.h"
 #endif
