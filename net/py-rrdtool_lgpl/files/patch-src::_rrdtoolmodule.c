--- src/_rrdtoolmodule.c.orig	Tue May 10 15:02:49 2005
+++ src/_rrdtoolmodule.c	Tue May 10 15:06:59 2005
@@ -232,11 +232,13 @@
     PyObject        *r;
     char           **argv, **calcpr;
     int              argc, xsize, ysize, i;
+    double           ymin, ymax;
 
     if (create_args("graph", args, &argc, &argv) < 0)
         return NULL;
 
-    if (rrd_graph(argc, argv, &calcpr, &xsize, &ysize) == -1) {
+    if (rrd_graph(argc, argv, &calcpr, &xsize, &ysize, NULL,
+                  &ymin, &ymax) == -1) {
         PyErr_SetString(ErrorObject, rrd_get_error());
         rrd_clear_error();
         r = NULL;
