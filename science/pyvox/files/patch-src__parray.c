--- ./src/parray.c.orig	2006-02-24 12:18:51.000000000 -0500
+++ ./src/parray.c	2011-07-01 02:32:12.000000000 -0400
@@ -991,7 +991,7 @@
     if (DEBUG_ALLOC) {
 	fprintf(stderr, "parray create:  %p\n", self);
 	if (0) 
-	    fprintf(stderr, "...reference count = %d\n",
+	    fprintf(stderr, "...reference count = %zd\n",
 		    ((PyObject *)self)->ob_refcnt); 
     }
 
@@ -1171,7 +1171,7 @@
     if (DEBUG_ALLOC) {
 	fprintf(stderr, "parray alloc:   %p\n", self);
 	if (0) 
-	    fprintf(stderr, "...reference count = %d\n",
+	    fprintf(stderr, "...reference count = %zd\n",
 		    ((PyObject *)self)->ob_refcnt); 
     }
 
@@ -2074,7 +2074,7 @@
 
 static PyMappingMethods
 parray_as_mapping = {
-    (inquiry)       parray_length,    /* mp_length:        len(x)   */
+    (lenfunc)       parray_length,    /* mp_length:        len(x)   */
     (binaryfunc)    parray_getitem,   /* mp_subscript:     x[y]     */
     (objobjargproc) parray_setitem,   /* mp_ass_subscript: x[y] = v */
 };
@@ -2204,13 +2204,13 @@
 
 static PySequenceMethods 
 parray_as_sequence = {
-    (inquiry)          0,                  /* sq_length:     len(x)     */
+    (lenfunc)          0,                  /* sq_length:     len(x)     */
     (binaryfunc)       0,                  /* sq_concat:     x + y      */
-    (intargfunc)       0,                  /* sq_repeat:     n * x      */
-    (intargfunc)       0,                  /* sq_item:       x[i]       */
-    (intintargfunc)    parray_getslice,    /* sq_slice:      x[i:j]     */
-    (intobjargproc)    0,                  /* sq_ass_item:   x[i] = v   */
-    (intintobjargproc) parray_setslice,    /* sq_ass_slice:  x[i:j] = v */
+    (ssizeargfunc)       0,                  /* sq_repeat:     n * x      */
+    (ssizeargfunc)       0,                  /* sq_item:       x[i]       */
+    (ssizessizeargfunc)    parray_getslice,    /* sq_slice:      x[i:j]     */
+    (ssizeobjargproc)    0,                  /* sq_ass_item:   x[i] = v   */
+    (ssizessizeobjargproc) parray_setslice,    /* sq_ass_slice:  x[i:j] = v */
 };
 
 
@@ -7386,7 +7386,7 @@
 
     /* DEBUG: Print ref counts of arguments */
     if (0) {
-      printf("Refcnts 1: %d, %d\n", self->ob_refcnt, filename->ob_refcnt);
+      printf("Refcnts 1: %zd, %zd\n", self->ob_refcnt, filename->ob_refcnt);
     }
 
     /* Paste self onto front of argument tuple.  FIXME: This is really
@@ -7400,7 +7400,7 @@
 
     /* DEBUG: Print ref counts of arguments */
     if (0) {
-      printf("Refcnts 2: %d, %d, %d\n", self->ob_refcnt, filename->ob_refcnt,
+      printf("Refcnts 2: %zd, %zd, %zd\n", self->ob_refcnt, filename->ob_refcnt,
 	     newargs->ob_refcnt);
     }
 
@@ -7418,7 +7418,7 @@
 
     /* DEBUG: Print ref counts of arguments */
     if (0) {
-      printf("Refcnts 3: %d, %d, %d\n", self->ob_refcnt, filename->ob_refcnt,
+      printf("Refcnts 3: %zd, %zd, %zd\n", self->ob_refcnt, filename->ob_refcnt,
 	     newargs->ob_refcnt);
     }
 
