--- kernel/sources/learn_f.c.orig	Sat Sep 28 20:55:45 2002
+++ kernel/sources/learn_f.c	Sat Sep 28 20:56:31 2002
@@ -33,6 +33,8 @@
 #include <math.h>
 #ifdef HAVE_VALUES_H
 #include <values.h>
+#else
+#include <limits.h>
 #endif
 #include <ctype.h>
 
@@ -3896,8 +3898,8 @@
 
   /* NULL before first  unit */
   topo_ptr = topo_ptr_array;
-  xmin_in = ymin_in =  MAXINT;
-  xmax_in = ymax_in = -MAXINT;
+  xmin_in = ymin_in =  INT_MAX;
+  xmax_in = ymax_in = -INT_MAX;
 
   while ( (input_unit_ptr = * ++topo_ptr ) != NULL)
     {
@@ -3967,8 +3969,8 @@
 
   /* topo_ptr points now to the NULL before first output unit */
 
-  xmin_out = ymin_out =  MAXINT;
-  xmax_out = ymax_out = -MAXINT;
+  xmin_out = ymin_out =  INT_MAX;
+  xmax_out = ymax_out = -INT_MAX;
 
   while ( (output_unit_ptr = * ++topo_ptr ) != NULL)
     {
