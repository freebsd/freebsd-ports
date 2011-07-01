--- ./src/tkphoto.c.orig	2005-12-29 13:33:15.000000000 -0500
+++ ./src/tkphoto.c	2011-07-01 02:28:06.000000000 -0400
@@ -632,7 +632,7 @@
     if (0) {
 	fprintf(stderr, "Created new tkphoto object at %p\n", self);
 	if (0) 
-	    fprintf(stderr, "...reference count = %d\n",
+	    fprintf(stderr, "...reference count = %zd\n",
 		    ((PyObject *)pytk)->ob_refcnt); 
     }
 
