--- src/input/r_dts.cpp.orig	2015-06-08 14:20:03 UTC
+++ src/input/r_dts.cpp
@@ -23,6 +23,10 @@
 #include "merge/input_x.h"
 #include "output/p_dts.h"
 
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+
 #define READ_SIZE 16384
 
 int
