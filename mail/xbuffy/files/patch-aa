diff -ur ../../xbuffy-3.3.bl.3/libdyn/dyn_append.c ./libdyn/dyn_append.c
--- ../../xbuffy-3.3.bl.3/libdyn/dyn_append.c	Fri Feb 20 17:54:14 1998
+++ ./libdyn/dyn_append.c	Tue May  8 13:13:43 2001
@@ -11,6 +11,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 
 #include "dynP.h"
 
@@ -20,7 +21,7 @@
    int num;
 {
      if (obj->debug)
-	  fprintf(stderr, "dyn: append: Writing %d bytes from %d to %d + %d\n",
+	  fprintf(stderr, "dyn: append: Writing %d bytes from %p to %p + %d\n",
 		  obj->el_size*num, els, obj->array, obj->num_el*obj->el_size);
 
      if (obj->size < obj->num_el + num) {
