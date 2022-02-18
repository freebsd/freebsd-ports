--- libinterp/dldfcn/convhulln.cc.orig	2021-10-30 14:20:24 UTC
+++ libinterp/dldfcn/convhulln.cc
@@ -53,7 +53,7 @@
 
 #  include "oct-qhull.h"
 
-#  if defined (NEED_QHULL_VERSION)
+#  if defined (NEED_QHULL_R_VERSION)
 char qh_version[] = "convhulln.oct 2007-07-24";
 #  endif
 
@@ -64,12 +64,12 @@ close_fcn (FILE *f)
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
     warning ("convhulln: did not free %d bytes of long memory (%d pieces)",
@@ -188,25 +188,22 @@ convex hull is calculated.
 
   frame.add_fcn (close_fcn, outfile);
 
-  // qh_new_qhull command and points arguments are not const...
+  qhT context = { 0 };
+  qhT *qh = &context;
 
   std::string cmd = "qhull" + options;
 
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
     error ("convhulln: qhull failed");
 
   bool nonsimp_seen = false;
 
-  octave_idx_type nf = qh num_facets;
+  octave_idx_type nf = qh->num_facets;
 
   Matrix idx (nf, dim + 1);
 
@@ -218,7 +215,7 @@ convex hull is calculated.
     {
       octave_idx_type j = 0;
 
-      if (! (nonsimp_seen || facet->simplicial || qh hull_dim == 2))
+      if (! (nonsimp_seen || facet->simplicial || qh->hull_dim == 2))
         {
           nonsimp_seen = true;
 
@@ -229,14 +226,14 @@ convex hull is calculated.
 
       if (dim == 3)
         {
-          setT *vertices = qh_facet3vertex (facet);
+          setT *vertices = qh_facet3vertex (qh, facet);
 
           vertexT *vertex, **vertexp;
 
           FOREACHvertex_ (vertices)
-            idx(i, j++) = 1 + qh_pointid(vertex->point);
+            idx(i, j++) = 1 + qh_pointid(qh, vertex->point);
 
-          qh_settempfree (&vertices);
+          qh_settempfree (qh, &vertices);
         }
       else
         {
@@ -245,14 +242,14 @@ convex hull is calculated.
               vertexT *vertex, **vertexp;
 
               FOREACHvertex_ (facet->vertices)
-                idx(i, j++) = 1 + qh_pointid(vertex->point);
+                idx(i, j++) = 1 + qh_pointid(qh, vertex->point);
             }
           else
             {
               vertexT *vertex, **vertexp;
 
               FOREACHvertexreverse12_ (facet->vertices)
-                idx(i, j++) = 1 + qh_pointid(vertex->point);
+                idx(i, j++) = 1 + qh_pointid(qh, vertex->point);
             }
         }
       if (j < dim)
@@ -280,26 +277,26 @@ convex hull is calculated.
           if (! facet->normal)
             continue;
 
-          if (facet->upperdelaunay && qh ATinfinity)
+          if (facet->upperdelaunay && qh->ATinfinity)
             continue;
 
-          facet->f.area = area = qh_facetarea (facet);
+          facet->f.area = area = qh_facetarea (qh, facet);
           facet->isarea = True;
 
-          if (qh DELAUNAY)
+          if (qh->DELAUNAY)
             {
-              if (facet->upperdelaunay == qh UPPERdelaunay)
-                qh totarea += area;
+              if (facet->upperdelaunay == qh->UPPERdelaunay)
+                qh->totarea += area;
             }
           else
             {
-              qh totarea += area;
-              qh_distplane (qh interior_point, facet, &dist);
-              qh totvol += -dist * area/ qh hull_dim;
+              qh->totarea += area;
+              qh_distplane (qh, qh->interior_point, facet, &dist);
+              qh->totvol += -dist * area / qh->hull_dim;
             }
         }
 
-      retval(1) = octave_value (qh totvol);
+      retval(1) = octave_value (qh->totvol);
     }
 
   retval(0) = idx;
