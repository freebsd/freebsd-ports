--- src/mat.cpp.orig	Thu Aug  8 16:29:42 2002
+++ src/mat.cpp	Thu Aug  8 16:29:55 2002
@@ -12,6 +12,7 @@
 
 #include <math.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include "mat.h"
 
 void inverse(view *in, view *out)
