--- Src/umathmodule.c.orig	2005-04-20 18:48:47 UTC
+++ Src/umathmodule.c
@@ -1,9 +1,9 @@
 
+#include <math.h>
 #include "Python.h"
 #include "Numeric/arrayobject.h"
 #include "Numeric/ufuncobject.h"
 #include "abstract.h"
-#include <math.h>
 
 #ifndef CHAR_BIT
 #define CHAR_BIT 8
