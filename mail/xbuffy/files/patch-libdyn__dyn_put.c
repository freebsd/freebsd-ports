diff -ur ../../xbuffy-3.3.bl.3/libdyn/dyn_put.c ./libdyn/dyn_put.c
--- ../../xbuffy-3.3.bl.3/libdyn/dyn_put.c	Fri Feb 20 17:54:14 1998
+++ ./libdyn/dyn_put.c	Tue May  8 13:13:44 2001
@@ -11,6 +11,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 
 #include "dynP.h"
 
@@ -34,7 +35,7 @@
      }
      
      if (obj->debug)
-	  fprintf(stderr, "dyn: get: Returning address %d + %d.\n",
+	  fprintf(stderr, "dyn: get: Returning address %p + %d.\n",
 		  obj->array, obj->el_size*num);
      
      return (DynPtr) obj->array + obj->el_size*num;
@@ -67,7 +68,7 @@
      int ret;
      
      if (obj->debug)
-	  fprintf(stderr, "dyn: put: Writing %d bytes from %d to %d + %d\n",
+	  fprintf(stderr, "dyn: put: Writing %d bytes from %p to %p + %d\n",
 		  obj->el_size, el, obj->array, index*obj->el_size);
 
      if ((ret = _DynResize(obj, index)) != DYN_OK)
