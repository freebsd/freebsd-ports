--- libinterp/dldfcn/__voronoi__.cc.orig	2021-10-30 14:20:24 UTC
+++ libinterp/dldfcn/__voronoi__.cc
@@ -60,7 +60,7 @@ qhull command
 
 #  include "oct-qhull.h"
 
-#  if defined (NEED_QHULL_VERSION)
+#  if defined (NEED_QHULL_R_VERSION)
 char qh_version[] = "__voronoi__.oct 2007-07-24";
 #  endif
 
@@ -71,12 +71,12 @@ close_fcn (FILE *f)
 }
 
 static void
-free_qhull_memory ()
+free_qhull_memory (qhT *qh)
 {
-  qh_freeqhull (! qh_ALL);
+  qh_freeqhull (qh, ! qh_ALL);
 
   int curlong, totlong;
-  qh_memfreeshort (&curlong, &totlong);
+  qh_memfreeshort (qh, &curlong, &totlong);
 
   if (curlong || totlong)
     warning ("__voronoi__: did not free %d bytes of long memory (%d pieces)",
@@ -173,35 +173,32 @@ Undocumented internal function.
 
   frame.add_fcn (close_fcn, outfile);
 
-  // qh_new_qhull command and points arguments are not const...
+  qhT context = { 0 };
+  qhT *qh = &context;
 
   std::string cmd = "qhull v" + options;
 
-  OCTAVE_LOCAL_BUFFER (char, cmd_str, cmd.length () + 1);
+  int exitcode = qh_new_qhull (qh, dim, num_points, points.fortran_vec (),
+                               ismalloc, &cmd[0], outfile, errfile);
 
-  strcpy (cmd_str, cmd.c_str ());
+  octave::unwind_action free_memory ([qh] () { free_qhull_memory (qh); });
 
-  int exitcode = qh_new_qhull (dim, num_points, points.fortran_vec (),
-                               ismalloc, cmd_str, outfile, errfile);
-
-  frame.add_fcn (free_qhull_memory);
-
   if (exitcode)
     error ("%s: qhull failed", caller.c_str ());
 
   // Calling findgood_all provides the number of Voronoi vertices
-  // (sets qh num_good).
+  // (sets qh->num_good).
 
-  qh_findgood_all (qh facet_list);
+  qh_findgood_all (qh, qh->facet_list);
 
   octave_idx_type num_voronoi_regions
-    = qh num_vertices - qh_setsize (qh del_vertices);
+    = qh->num_vertices - qh_setsize (qh, qh->del_vertices);
 
-  octave_idx_type num_voronoi_vertices = qh num_good;
+  octave_idx_type num_voronoi_vertices = qh->num_good;
 
   // Find the voronoi centers for all facets.
 
-  qh_setvoronoi_all ();
+  qh_setvoronoi_all (qh);
 
   facetT *facet;
   vertexT *vertex;
@@ -224,8 +221,8 @@ Undocumented internal function.
 
   FORALLvertices
     {
-      if (qh hull_dim == 3)
-        qh_order_vertexneighbors (vertex);
+      if (qh->hull_dim == 3)
+        qh_order_vertexneighbors (qh, vertex);
 
       bool infinity_seen = false;
 
@@ -289,12 +286,12 @@ Undocumented internal function.
 
   FORALLvertices
     {
-      if (qh hull_dim == 3)
-        qh_order_vertexneighbors (vertex);
+      if (qh->hull_dim == 3)
+        qh_order_vertexneighbors (qh, vertex);
 
       bool infinity_seen = false;
 
-      octave_idx_type idx = qh_pointid (vertex->point);
+      octave_idx_type idx = qh_pointid (qh, vertex->point);
 
       octave_idx_type num_vertices = ni[k++];
 
