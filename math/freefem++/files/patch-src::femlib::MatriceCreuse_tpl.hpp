--- ./src/femlib/MatriceCreuse_tpl.hpp.orig	Mon Aug 30 17:06:00 2004
+++ ./src/femlib/MatriceCreuse_tpl.hpp	Wed Sep  8 22:18:17 2004
@@ -11,7 +11,9 @@
 //  on MacOS9 under MWERKS
 //  cblas_ddot macos-9 is not 
 #ifdef HAVE_CBLAS_H
-#include <cblas.h> 
+extern "C" {
+#include <cblas.h>
+}
 #define WITHBLAS 1
 #elif HAVE_VECLIB_CBLAS_H
 #include <vecLib/cblas.h> 
