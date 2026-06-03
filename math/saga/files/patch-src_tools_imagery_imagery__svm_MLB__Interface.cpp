--- src/tools/imagery/imagery_svm/MLB_Interface.cpp.orig	2026-04-10 09:39:35 UTC
+++ src/tools/imagery/imagery_svm/MLB_Interface.cpp
@@ -61,7 +61,7 @@
 #include "MLB_Interface.h"
 
 #if defined(SYSTEM_SVM)
-#include <libsvm/svm.h>
+#include <svm.h>
 #else
 #include "svm/svm.h"
 #endif
