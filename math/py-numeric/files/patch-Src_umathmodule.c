--- Src/umathmodule.c.orig	Wed Jan 12 12:45:18 2005
+++ Src/umathmodule.c	Wed Jan 12 12:45:29 2005
@@ -1,9 +1,9 @@
 
+#include <math.h>
 #include "Python.h"
 #include "Numeric/arrayobject.h"
 #include "Numeric/ufuncobject.h"
 #include "abstract.h"
-#include <math.h>
 
 #ifndef CHAR_BIT
 #define CHAR_BIT 8
