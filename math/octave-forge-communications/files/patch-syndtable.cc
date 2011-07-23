--- src/syndtable.cc-orig	2011-07-22 23:25:35.000000000 +0000
+++ src/syndtable.cc	2011-07-22 23:26:01.000000000 +0000
@@ -27,6 +27,7 @@
 #include <sstream>
 #include <octave/oct.h>
 #include <octave/pager.h>
+#include <octave/Array2.h>
 
 #define COL_MAJ(N) (N / (SIZEOF_INT << 3))
 #define COL_MIN(N) (N % (SIZEOF_INT << 3))
