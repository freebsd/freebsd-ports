diff -ur ../../xbuffy-3.3.bl.3/libdyn/dyn_realloc.c ./libdyn/dyn_realloc.c
--- ../../xbuffy-3.3.bl.3/libdyn/dyn_realloc.c	Fri Feb 20 17:54:14 1998
+++ ./libdyn/dyn_realloc.c	Tue May  8 13:13:44 2001
@@ -11,6 +11,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 
 #include "dynP.h"
 
