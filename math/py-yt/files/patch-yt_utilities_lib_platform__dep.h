--- yt/utilities/lib/platform_dep.h.orig	2017-01-01 20:57:35 UTC
+++ yt/utilities/lib/platform_dep.h
@@ -57,7 +57,7 @@ double erf(double x)
 
 #else
 #include <stdint.h>
-#include "alloca.h"
+#include <stdlib.h>
 #include <math.h>
 #endif
 
