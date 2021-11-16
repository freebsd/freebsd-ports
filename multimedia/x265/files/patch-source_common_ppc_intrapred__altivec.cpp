--- source/common/ppc/intrapred_altivec.cpp.orig	2021-11-16 17:20:04 UTC
+++ source/common/ppc/intrapred_altivec.cpp
@@ -27,7 +27,11 @@
 #include <assert.h>
 #include <math.h>
 #include <cmath>
+#ifdef __linux__
 #include <linux/types.h>
+#else
+#include <sys/types.h>
+#endif
 #include <stdlib.h>
 #include <stdio.h>
 #include <stdint.h>
