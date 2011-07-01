--- ./src/pyvox.c.orig	2006-02-24 16:33:41.000000000 -0500
+++ ./src/pyvox.c	2011-07-01 02:29:06.000000000 -0400
@@ -1850,7 +1850,7 @@
     if (0) {
 	fprintf(stderr, "Created new kernel object at %p\n", self);
 	if (0) 
-	    fprintf(stderr, "...reference count = %d\n",
+	    fprintf(stderr, "...reference count = %zd\n",
 		    ((PyObject *)self)->ob_refcnt); 
     }
 
@@ -2273,7 +2273,7 @@
 
 static PyMappingMethods
 kernel_as_mapping = {
-    (inquiry)       kernel_length,    /* mp_length:        len(x)   */
+    (lenfunc)       kernel_length,    /* mp_length:        len(x)   */
     (binaryfunc)    kernel_getitem,   /* mp_subscript:     x[y]     */
     (objobjargproc) kernel_setitem,   /* mp_ass_subscript: x[y] = v */
 };
