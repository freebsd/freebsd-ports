--- src/gf.cc-orig	2011-07-22 23:41:54.000000000 +0000
+++ src/gf.cc	2011-07-22 23:42:13.000000000 +0000
@@ -49,6 +49,7 @@
 #include "ov-galois.h"
 #include <octave/utils.h>
 #include <octave/variables.h>
+#include <octave/Array2.h>
 
 static bool galois_type_loaded = false;
 
