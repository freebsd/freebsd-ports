--- Src/umathmodule.c.orig	Sat Aug  2 01:10:09 2003
+++ Src/umathmodule.c	Sat Aug  2 01:10:43 2003
@@ -1,9 +1,9 @@
 
+#include <math.h>
 #include "Python.h"
 #include "Numeric/arrayobject.h"
 #include "Numeric/ufuncobject.h"
 #include "abstract.h"
-#include <math.h>
 
 #ifndef CHAR_BIT
 #define CHAR_BIT 8
