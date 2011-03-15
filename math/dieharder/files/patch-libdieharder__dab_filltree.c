--- ./libdieharder/dab_filltree.c.orig	2011-03-15 05:51:27.000000000 -0400
+++ ./libdieharder/dab_filltree.c	2011-03-15 06:00:44.000000000 -0400
@@ -148,6 +148,7 @@
  }
 
  //  for (i = 0; i < size; i++) printf("%f\n", array[i]);
+nullfree(array);
 
  return(0);
 }
