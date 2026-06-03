--- src/tools/imagery/imagery_svm/svm_grids.h.orig	2026-04-10 09:39:35 UTC
+++ src/tools/imagery/imagery_svm/svm_grids.h
@@ -61,7 +61,7 @@
 
 //---------------------------------------------------------
 #if defined(SYSTEM_SVM)
-	#include <libsvm/svm.h>
+	#include <svm.h>
 #else
 	#include "svm/svm.h"
 #endif
