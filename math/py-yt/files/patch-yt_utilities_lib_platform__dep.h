--- yt/utilities/lib/platform_dep.h.orig	2021-08-02 20:27:17 UTC
+++ yt/utilities/lib/platform_dep.h
@@ -59,6 +59,10 @@ double erf(double x)
 
 #else
 #include <stdint.h>
-#include "alloca.h"
+#if !defined(__FreeBSD__)
+#  include "alloca.h"
+#else
+#  include <stdlib.h>
+#endif
 #include <math.h>
 #endif
