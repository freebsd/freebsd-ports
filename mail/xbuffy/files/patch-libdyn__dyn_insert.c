diff -ur ../../xbuffy-3.3.bl.3/libdyn/dyn_insert.c ./libdyn/dyn_insert.c
--- ../../xbuffy-3.3.bl.3/libdyn/dyn_insert.c	Fri Feb 20 17:54:14 1998
+++ ./libdyn/dyn_insert.c	Tue May  8 13:13:43 2001
@@ -11,6 +11,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include "dynP.h"
 
 int DynInsert(obj, index, els, num)
@@ -35,7 +36,7 @@
      }
 
      if (obj->debug)
-	  fprintf(stderr,"dyn: insert: Moving %d bytes from %d + %d to + %d\n",
+	  fprintf(stderr,"dyn: insert: Moving %d bytes from %p + %d to + %d\n",
 		  (obj->num_el-index)*obj->el_size, obj->array,
 		  obj->el_size*index, obj->el_size*(index+num));
 
@@ -46,7 +47,7 @@
 	   (obj->num_el-index)*obj->el_size);
 
      if (obj->debug)
-	  fprintf(stderr, "dyn: insert: Copying %d bytes from %d to %d + %d\n",
+	  fprintf(stderr, "dyn: insert: Copying %d bytes from %p to %p + %d\n",
 		  obj->el_size*num, els, obj->array, obj->el_size*index);
 
      bcopy(els, obj->array + obj->el_size*index, obj->el_size*num);
