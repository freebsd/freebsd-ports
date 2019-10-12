--- src/ColSpec.h.orig	2019-09-24 16:05:20 UTC
+++ src/ColSpec.h
@@ -1,6 +1,7 @@
 #ifndef READXL_COLSPEC_
 #define READXL_COLSPEC_
 
+#include <sys/types.h>
 #include <Rcpp.h>
 #include <libxls/xls.h>
 #include "StringSet.h"
