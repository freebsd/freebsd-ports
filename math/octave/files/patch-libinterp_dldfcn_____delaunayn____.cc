--- libinterp/dldfcn/__delaunayn__.cc.orig	2021-10-30 14:20:24 UTC
+++ libinterp/dldfcn/__delaunayn__.cc
@@ -65,7 +65,7 @@
 
 #  include "oct-qhull.h"
 
-#  if defined (NEED_QHULL_VERSION)
+#  if defined (NEED_QHULL_R_VERSION)
 char qh_version[] = "__delaunayn__.oct 2007-08-21";
 #  endif
 
@@ -76,12 +76,12 @@ close_fcn (FILE *f)
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
     warning ("__delaunayn__: did not free %d bytes of long memory (%d pieces)",
@@ -161,11 +161,8 @@ Undocumented internal function.
       double *pt_array = p.fortran_vec ();
       boolT ismalloc = false;
 
-      // Qhull flags argument is not const char*
-      OCTAVE_LOCAL_BUFFER (char, flags, 9 + options.length ());
+      std::string cmd = "qhull d " + options;
 
-      sprintf (flags, "qhull d %s", options.c_str ());
-
       octave::unwind_protect frame;
 
       // Replace the outfile pointer with stdout for debugging information.
@@ -181,16 +178,19 @@ Undocumented internal function.
 
       frame.add_fcn (close_fcn, outfile);
 
-      int exitcode = qh_new_qhull (dim, n, pt_array,
-                                   ismalloc, flags, outfile, errfile);
+      qhT context = { 0 };
+      qhT *qh = &context;
 
-      frame.add_fcn (free_qhull_memory);
+      int exitcode = qh_new_qhull (qh, dim, n, pt_array, ismalloc, &cmd[0],
+                                   outfile, errfile);
 
+      octave::unwind_action free_memory ([qh] () { free_qhull_memory (qh); });
+
       if (exitcode)
         error ("__delaunayn__: qhull failed");
 
       // triangulate non-simplicial facets
-      qh_triangulate ();
+      qh_triangulate (qh);
 
       facetT *facet;
       vertexT *vertex, **vertexp;
@@ -217,7 +217,7 @@ Undocumented internal function.
 
               FOREACHvertex_ (facet->vertices)
                 {
-                  simpl(i, j++) = 1 + qh_pointid(vertex->point);
+                  simpl(i, j++) = 1 + qh_pointid(qh, vertex->point);
                 }
               i++;
             }
