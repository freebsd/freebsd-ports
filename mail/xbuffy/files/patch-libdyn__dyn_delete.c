diff -ur ../../xbuffy-3.3.bl.3/libdyn/dyn_delete.c ./libdyn/dyn_delete.c
--- ../../xbuffy-3.3.bl.3/libdyn/dyn_delete.c	Fri Feb 20 17:54:14 1998
+++ ./libdyn/dyn_delete.c	Tue May  8 13:13:43 2001
@@ -11,6 +11,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 
 #include "dynP.h"
 
@@ -45,7 +46,7 @@
      else {
 	  if (obj->debug)
 	       fprintf(stderr,
-		       "dyn: delete: copying %d bytes from %d + %d to + %d.\n",
+		       "dyn: delete: copying %d bytes from %p + %d to + %d.\n",
 		       obj->el_size*(obj->num_el - index), obj->array,
 		       (index+1)*obj->el_size, index*obj->el_size);
 	  
@@ -56,7 +57,7 @@
 	  if (obj->paranoid) {
 	       if (obj->debug)
 		    fprintf(stderr,
-			    "dyn: delete: zeroing %d bytes from %d + %d\n",
+			    "dyn: delete: zeroing %d bytes from %p + %d\n",
 			    obj->el_size, obj->array,
 			    obj->el_size*(obj->num_el - 1));
 	       bzero(obj->array + obj->el_size*(obj->num_el - 1),
