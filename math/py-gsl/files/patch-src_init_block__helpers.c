
$FreeBSD$

--- src/init/block_helpers.c.orig
+++ src/init/block_helpers.c
@@ -380,8 +380,9 @@
 	       goto fail;	    
 	  }	 
 	  FUNC_MESS("=> FLOAT");
-	  int dim = 1;
+	  { int dim = 1;
 	  r = (PyArrayObject *) PyGSL_New_Array(1, &dim, PyArray_DOUBLE);
+	  }
 	  if(r == NULL) {
 	       line = __LINE__ - 2;
 	       goto fail;
