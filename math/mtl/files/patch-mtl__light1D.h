--- mtl/light1D.h.orig	2007-04-10 16:03:10.000000000 -0400
+++ mtl/light1D.h	2012-01-01 03:58:53.000000000 -0500
@@ -19,7 +19,8 @@
 #include "mtl/reverse_iter.h"
 #include "mtl/matrix_traits.h"
 #include "mtl/scaled1D.h"
-#include <stdlib.h>
+#include <cstddef>
+#include <cstdlib>
 
 namespace mtl {
 
