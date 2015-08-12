--- src/input/r_dts.cpp.orig	2015-07-18 11:39:41 UTC
+++ src/input/r_dts.cpp
@@ -27,6 +27,10 @@
 #include "merge/input_x.h"
 #include "output/p_dts.h"
 
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+
 #define READ_SIZE 16384
 
 int
